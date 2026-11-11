#include <bits/stdc++.h>
using namespace std;

long long n, ans = 0;

struct node
{
    int cnt;
    char c;
}a[200005];

long long hui_wen()
{
    int l = 1, r = n;
    int next = r;
    node t;
    t.cnt = a[l].cnt;
    t.c = a[l].c;
    while (l <= r)
    {
        if (t.cnt != 0)
        {
            if (t.cnt > a[next].cnt)
            {
                if (t.c != a[next].c) ans += a[next].cnt;
                t.cnt = t.cnt - a[next].cnt;
                if (next == l) l++, next = l;
                else r--, next = r;
            }
            else
            {
                if (t.c != a[next].c) ans += t.cnt;
                t.cnt = a[next].cnt - t.cnt;
                t.c = a[next].c;
                if (next == l) r--, next = r;
                else l++, next = l;
            }
        }
        else
        {
            if (next == l)
            {
                r--;
                t.cnt = a[r].cnt;
                t.c = a[r].c;
            }
            else
            {
                l++;
                t.cnt = a[l].cnt;
                t.c = a[l].c;
            }
        }
    }
    return ans;
}

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].cnt >> a[i].c;
    }
    cout << hui_wen();
    return 0;
}
