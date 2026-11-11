#include <bits/stdc++.h>

using namespace std;

int n, m;

int a[500010];

int vis[500010];

int ans[500010];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int st = 1; st <= n; st++)
    {
        memset(vis, 0, sizeof(vis));
        for (int i = st; i <= n; i++)
        {
            if (vis[a[i]] == 0)
                vis[a[i]] = 1;
            else
            {
                for (int j = i - 1; j >= st; j--)
                {
                    if (a[i] == a[j])
                        break;
                    vis[a[j]] = 0;
                }
            }
        }
        for (int i = 1; i <= m; i++)
        {
            ans[i] += vis[i];
        }
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << " ";
    return 0;
}
