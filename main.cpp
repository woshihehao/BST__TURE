//
//  main.cpp
//  vhj
//
//  Created by 何灏 on 16/3/10.
//  Copyright © 2016年 UESTCOpenSource. All rights reserved.
//
#include <iostream>
using namespace std;

// BST的结点
typedef struct node
{
    int key;
    struct node *lChild, *rChild;
}Node, *BST;

// 在给定的BST中插入结点，其数据域为element, 使之称为新的BST
bool BSTInsert(Node * &p, int element)
{
    if(NULL == p) // 空树
    {
        p = new Node;
        p->key = element;
        p->lChild = p->rChild = NULL;
        return true;
    }
    
    if(element == p->key) // BST中不能有相等的值
        return false;
    
    if(element < p->key)  // 递归
        return BSTInsert(p->lChild, element);
    
    return BSTInsert(p->rChild, element); // 递归
}

// 建立BST
void createBST(Node * &T, int a[], int n)
{
    T = NULL;
    int i;
    for(i = 0; i < n; i++)
    {
        BSTInsert(T, a[i]);
    }
}

// 先序遍历
void preOrderTraverse(BST T)
{
    if(T)
    {
        cout << T->key << " ";
        preOrderTraverse(T->lChild);
        preOrderTraverse(T->rChild);
    }
}

// 中序遍历
void inOrderTraverse(BST T)
{
    if(T)
    {
        inOrderTraverse(T->lChild);
        cout << T->key << " ";
        inOrderTraverse(T->rChild);
    }
}

int main()
{
    int a[10] = {4, 5, 2, 1, 0, 9, 3, 7, 6, 8};
    int n = 10;
    BST T;
    
    // 并非所有的a[]都能构造出BST,所以，最好对createBST的返回值进行判断
    createBST(T, a, n);
    
    preOrderTraverse(T);
    cout << endl;
    
    inOrderTraverse(T);
    cout << endl;
    
    return 0;
}