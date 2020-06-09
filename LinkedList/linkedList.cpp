#include <bits/stdc++.h>
using namespace std;

//Node of LinkedList
struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

//Inserting new data into linkedList
Node *insert(Node *head, int data)
{
    if (head == NULL)
        return new Node(data);

    Node *t = head;

    while (head->next)
    {
        head = head->next;
    }

    head->next = new Node(data);

    return t;
}

//Printing the LinkedList
void print(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

//Deleting the node
Node *deleteNode(Node *head)
{
    Node *t = head;
    if (head == NULL || head->next == NULL)
        return NULL;

    while (head->next && head->next->next)
    {
        head = head->next;
    }

    // delete (head->next);
    head->next = NULL;
    return t;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        head = insert(head, arr[i]);
        print(head);
    }

    int p = 9;
    while (p--)
    {
        head = deleteNode(head);
        print(head);
    }
    return 0;
}
