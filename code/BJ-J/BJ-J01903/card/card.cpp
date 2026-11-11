#include <bits/stdc++.h>
using namespace std;
typedef long long l;
l n, m, a[500010], ans[500010], b[500010];
bool vis[500010];
l last[500010];
void game(l g)
{
    for(l i = 1; i < g; i++) a[i] = -1;
    for(l i = g; i <= n; i++)
    {
        if(!vis[a[i]])
        {
            vis[a[i]] = true;
            last[a[i]] = i;
        }
        else
        {
            for(l j = last[a[i]]; j < i; j++)
            {
                vis[a[j]] = false;
                a[j] = -1;
            }
            last[a[i]] = i;
            vis[a[i]] = true;
        }
    }
    for(l i = 1; i <= n; i++)
    {
        if(a[i] != -1)
        {
            ans[a[i]]++;
        }
    }
}
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    l maxn = 0, minn = 2e9;
    for(l i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
        maxn = max(maxn, a[i]);
        minn = min(minn, a[i]);
    }
    for(l g = 1; g <= n; g++) //game
    {
        memset(last, -1, sizeof last);
        for(l e = 1; e <= n; e++)
        {
            a[e] = b[e];
            vis[e] = false;
        }
        game(g);
    }
    for(l i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
