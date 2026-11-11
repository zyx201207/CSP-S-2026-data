#include <bits/stdc++.h>
using namespace std;
const int N = 500001;
struct Node
{
    int val = -1;
    Node *nxt = NULL, *pre = NULL;
};
int n, m;
int a[N], cnt[N];
Node* head = new Node;
Node* tail = new Node;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int x = 1; x <= n; x++)
    {
        for (int i = x; i <= n; i++)
        {
            Node* tmp = new Node;
            tmp->val = a[i];
            if (i == x)
            {
                head->nxt = tmp;
                tail->pre = tmp;
                tmp->pre = head;
                tmp->nxt = tail;
                continue;
            }
            Node* now = head->nxt;
            bool flag = 0;
            while (now != NULL)
            {
                if (now->val == tmp->val)
                {
                    now->pre->nxt = tmp;
                    tmp->pre = now->pre;
                    tail->pre = tmp;
                    tmp->nxt = tail;
                    flag = 1;
                    break;
                }
                now = now->nxt;
            }
            if (!flag)
            {
                tmp->nxt = tail;
                tmp->pre = tail->pre;
                tail->pre->nxt = tmp;
                tail->pre = tmp;
            }
        }
        Node *nownd = head->nxt;
        while (nownd != NULL)
        {
            cnt[nownd->val]++;
            nownd = nownd->nxt;
        }
        head = new Node;
        tail = new Node;
    }
    for (int i = 1; i <= m; i++)
        cout << cnt[i] << ' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}