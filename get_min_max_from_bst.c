#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;


void gethighest(struct node *temp)
{
    if(temp->right==NULL)
    {
        printf("\n highest element is %d ",temp->data);
        return;
    }
    else
    {
        gethighest(temp->right);
    }
}

void getmin(struct node *temp)
{
    if(temp->left==NULL)
    {
        printf("\n the minimum element is %d",temp->data);
        return;
    }
    else
    {
        getmin(temp->left);
    }
}

void search(int key)
{
    if(root==NULL)
    {
        printf("\n no elements in the tree");
        printf("Key not found");
    }

    else
    {
        struct node *temp = root;

        while(temp!=NULL)
        {
            if(temp->data == key)
            {
                printf("\n Key found in the tree");
                break;
            }

            else if(temp->left == NULL && temp->right==NULL)
            {
                printf("Key not found in the tree");
                break;
            }

            else if(temp->data > key)
            {
                temp = temp->left;
            }

            else if(temp->data < key)
            {
                temp = temp->right;
            }
        }
    }
}

void inorder(struct node *root)
{
    if(root==NULL) return;
    else{
        inorder(root->left);
        printf("%3d ",root->data);
        inorder(root->right);
    }


}
void insert(int ele)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->left = NULL;
    newnode->right = NULL;

    if(root==NULL)
    {
        root = newnode;
    }

    else
    {
        struct node *temp;
        temp = root;
        while(temp!=NULL){

            if(temp->data > ele)
            {
                if(temp->left!=NULL)
                {
                    temp = temp->left;
                }

                else if(temp->left==NULL)
                {
                    temp->left=newnode;
                    break;
                }
            }

            else if(temp->data<ele)
            {
                if(temp->right !=NULL)
                {
                    temp=temp->right;
                }
                else if(temp->right == NULL)
                {
                    temp->right = newnode;
                    break;
                }
            }
        }
    }
}

int main()
{
    insert(100);
    insert(50);
    insert(200);
    insert(25);
    insert(90);

    printf("\n inorder traversal is :\n");
    inorder(root);

    gethighest(root);
    getmin(root);

}
