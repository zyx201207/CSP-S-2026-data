#include<bits/stdc++.h>

using namespace std;

struct Node
{
    bool f;
    int num;
}vis[205];
int n, m;
int a[200005], ans[205];
int main ()
{
    freopen ("card.in", "r", stdin);
    freopen ("card.out", "w", stdout);
    cin >> n >> m;
    memset (ans, 0, sizeof ans);
    for (int i = 1; i <= n; i++)
    {
        cin >>a[i];
    }
    if (m == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == a[n])
            {
                ans[a[i]]++;
            }
            else
            {
                ans[1]++;
                ans[2]++;
            }
        }
        cout << ans[1] << ' ' << ans[2];
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (vis[a[j]].f == true)
            {
                for (int k = vis[a[j]].num + 1; k < j; k++)
                {
                    vis[a[k]].f = false;
                }
                vis[a[j]].num = j;
            }
            else
            {
                vis[a[j]].f = true;
                vis[a[j]].num = j;
            }
        }
        for (int j = 1; j <= m; j++)
        {
            if (vis[j].f == true)
            {
                ans[j] ++;
            }
            vis[j].f = false;
            vis[j].num = 0;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}
