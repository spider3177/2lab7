#include<iostream>
using namespace std;


class node{
public:
    int data;
    node * left;
    node * right;
    node * parent;

    node(int value){
        data = value;
        left = NULL;
        right = NULL;
        parent = NULL;
    }  
};

class bst{
public:
    node * root;
    bst(){
        root = NULL;
    }
    void ins(int value){
        insert(root, value);
    }
    void insert(node *curr, int value){
        // If root is NULL, then create a node and make it root. 
        if (root == NULL) root = new node(value);
        // Else Decide to move left or right. 
        else if (value < curr->data)  {
            // if left is already NULL, create a new node and link it. 
            if (curr->left == NULL) {
                curr->left = new node(value);
                curr->left->parent = curr;
            }
            // Move left and call insert there. 
            else insert(curr->left, value);
        }
        else {
            // if right is already NULL, create a new node and link it. 
            if (curr->right == NULL) {
                curr->right = new node(value);
                curr->right->parent = curr;
            }
            // Move right and call insert there. 
            else insert(curr->right, value);
        }
    }
    void displayHelper(){
        display(root);
    }
    void display(node * curr){
        // Case for empty tree and leaf nodes children.
        if( curr ==  NULL) return;
        // IN order print.
        // Print left. 
        display(curr->left);
        // Print myself.
        cout << curr->data << ", ";
        // Print right.
        display(curr->right);
    }
    node * searchh(int value){
        return search(root, value);
    }
    node * search(node * curr, int value){
        // Are you the value? or Are you NULL?  if yes return curr
        if(curr == NULL || curr->data == value ) return curr;
        // else you search in right or left. 
        // Left
        else if(value < curr->data) return search(curr->left, value);
        // Right
        else  return search(curr->right, value);
    }
    void print2DUtil(node * root, int space)  
    {  
        // Base case  
        if (root == NULL)  
            return;  
        // Increase distance between levels  
        space += 5;  
        // Process right child first  
        print2DUtil(root->right, space);  
    
        // Print current node after space  
        // count  
        cout<<endl;  
        for (int i = 5; i < space; i++)  
            cout<<" ";  
        cout<<root->data<<"\n";  
    
        // Process left child  
        print2DUtil(root->left, space);  
    }  
  
    // Wrapper over print2DUtil()  
    void print2D()  
    {  
        cout << "******************************" << endl;
        // Pass initial space count as 0  
        print2DUtil(root, 0);  
        cout << "******************************" << endl;
        
    }

	//FIND MIN
	node * fmin(node * curr){
		if ( curr->left == NULL ) return curr;
		else fmin(curr->left);
		
	}
	
	//replace 
	void rap(int a, int b){
		repap(searchh(a),searchh(b));
	}
	node * repap(node * a, node * b){
		if(a->data > a->parent->data){
			a->parent->right = b;
			b->parent = a->parent;
			//if (a->data > b->data) b->right = a;
			//else b->left = a;
		}
		else{
			a->parent->left = b;
			b->parent = a->parent;
			//if (a->data > b->data) b->right = a;
			//else b->left = a;
		}
	}

    void binary_delete(int k){
		del(search (k));
	}
	void del(node * curr){
		if(curr->left != NULL and curr->right != NULL){
			fmin(curr->right) = node * a;
			curr->data=a->data;
			delete a;
		}
		else if(curr->left == NULL and curr->right != NULL){
			repap(curr,curr->right);
			delete curr;
		}
		else if(curr->right == NULL and curr->left != NULL){
			repap(curr,curr->left);
			delete curr;
		}
		else{
			delete curr;
		}        
    }

};

int main(){
    
    bst b1;
    b1.ins(4);
    b1.ins(2);
    b1.ins(3);
    b1.ins(1);
    b1.ins(6);
    b1.ins(5);
    b1.ins(7);
    b1.ins(8);
	
    b1.displayHelper();
    if(b1.searchh(3) != NULL){
        cout << endl << b1.searchh(3)->data << endl;
    }
	b1.print2D();
	//b1.rap(7,8);
	//b1.print2D();

//  b1.binary_delete(5);
//  b1.print2D();
//  b1.binary_delete(6);
//  b1.print2D();
//  cout << "Deleting 2" << endl;
//  b1.binary_delete(2);
//  b1.print2D();
//  b1.binary_delete(4);
//  b1.print2D();
//  b1.binary_delete(7);
//  b1.print2D();
//  b1.binary_delete(8);
//  b1.print2D();
//  b1.binary_delete(3);
//  b1.print2D();
//  b1.binary_delete(1);
//  b1.print2D();
//  b1.binary_delete(1);
//  b1.print2D();

}
