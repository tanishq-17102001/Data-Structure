#include <bits/stdc++.h>
using namespace std;
typedef struct _bstNode
{
    int data;
    struct _bstNode *left;
    struct _bstNode *right;
} BSTNode;
BSTNode *root = NULL;
BSTNode *createNode()
{
    BSTNode *t;
    t = (BSTNode *)malloc(sizeof(BSTNode));
    t->left = NULL;
    t->right = NULL;
    return t;
}

void insertNode(int data)
{
    BSTNode *t, *j;
    t = createNode();
    t->data = data;
    if (!root)
    {
        root = t;
        return;
    }
    j = root;
    while (1)
    {
        if (t->data > j->data) // right case
        {
            if (j->right == NULL) // adding node to end
            {
                j->right = t;
                break;
            }
            else
            {
                j = j->right; // iterating over right node
            }
        }
        else // left case
        {
            if (j->left == NULL) // adding node to end
            {
                j->left = t;
                break;
            }
            else // iterating over left node
            {
                j = j->left;
            }
        }
    }
}

void inorder(BSTNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}
vector<vector<int>> levelOrder(BSTNode *head)
{
    vector<vector<int>> ans;
    if(!head) return ans;
    queue<BSTNode *> q;
    q.push(head);
    while(!q.empty())
    {
        int sz=q.size();
        vector<int> temp;
        for(int e=0;e<sz;e++)
        {
            BSTNode *node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            temp.push_back(node->data);
        }
        ans.push_back(temp);
    }
    return ans;
}
void iterativeInorder(BSTNode *root)
{
    stack<BSTNode *> stk;
    BSTNode *head=root;
    while(head!=NULL || stk.empty()==false)
    {
        while(head!=NULL){
            stk.push(head);
            head=head->left;
        }
        head=stk.top();
        stk.pop();
        cout<<head->data<<endl;
        head=head->right;
    }
}
int main()
{
    insertNode(100);
    insertNode(50);
    insertNode(75);
    insertNode(25);
    insertNode(35);
    insertNode(20);
    insertNode(23);
    insertNode(24);
    insertNode(10);
    insertNode(70);
    insertNode(60);
    insertNode(90);
    insertNode(95);
    insertNode(85);
    insertNode(200);
    insertNode(150);
    insertNode(175);
    insertNode(250);
    insertNode(300);
    cout<<"Level Order\n";
    vector<vector<int>> level=levelOrder(root);
    for(vector<int> v:level)
    {
        for(int e:v) cout<<e<<" ";
        cout<<endl;
    }
    cout<<"Inorder\n";
    iterativeInorder(root);
    return 0;
}
