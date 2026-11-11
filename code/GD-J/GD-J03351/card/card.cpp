#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], lstl, cnt[300005], lstr;
struct node
{
    bool f;
    int d;
} v[300005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int i = 1; i <= m; i++)
            v[i] = {0, -3};
        lstl = lstr = -1;
        for (int j = i; j <= n; j++)
        {
            if (v[a[i]].f && v[a[i]].d > lstr || v[a[i]].d < lstl)
            {
                lstl = v[a[i]].d;
                lstr = j - 1;
                v[a[i]].d = j;
            }
            else
            {
                v[a[i]].f = 1;
                v[a[i]].d = j;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            cnt[i] += (v[i].f && (v[i].d > lstr || v[i].d < lstl));
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}
