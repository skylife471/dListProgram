#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* element;

typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

void init(DListNode* phead)
{
    phead->rlink = phead;
    phead->llink = phead;
}

void print_dlist(DListNode* phead, DListNode* current) // current ���� ���� ���� ���ִ� ������ head = current �� �����Ǿ��ֱ⶧���̴�.
{
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        if (p == current->rlink) {
            printf("%s [O]\n", p->data);
        }
        else {
            printf("%s\n", p->data);
        }
    }
    printf("\n");
}

void dinsert(DListNode* before, element item)
{
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    newnode->data = (element)malloc(strlen(item) + 1);  //strlen(item)+1 �� item���ڿ� ���� 1���ٰ� \0 �� �߰��ϱ� ���Ͽ�
    strcpy(newnode->data, item);  // �Ҵ�� �޸𸮷� ������ ����
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

void delete(DListNode* head, DListNode* removed)
{
    if (removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

DListNode* next_node(DListNode* current)
{
    return current->rlink;
}

DListNode* prev_node(DListNode* current)
{
    return current->llink;
}

int main(void)
{
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);
    DListNode* current = head->rlink;
    while (1)
    {
        char choice;
        char a[100];
        printf("==== MENU ====\n");
        printf("n) next fruit\n");
        printf("p) previous fruit\n");
        printf("d) delete the current fruit\n");
        printf("i) insert fruit after current fruit\n");
        printf("o) output the fruit list(Output [0] at the end of the currently selcted fruit)\n");
        printf("e) exit the program\n");
        printf("==============\n");
        printf("Select a menu: ");
        scanf("%s", &choice);
        switch (choice) {
        case 'n':
            current = next_node(current);
            printf("\n");
            break;
        case 'p':
            current = prev_node(current);
            printf("\n");
            break;
        case 'd':
            delete(current, current->rlink );
            printf("\n");
            break;
        case 'i':
            printf("Enter the name of the fruit to add: ");
            scanf("%s", a);
            printf("\n");
            dinsert(current->rlink , a);
            break;
        case 'o':
            print_dlist(head, current);
            break;
        case 'e':
            printf("exit the program.");
            exit(0);
        default:
            printf("Invalid Menu\n\n");
            break;

        }
    }
    return 0;
}