#include <bits/stdc++.h>
using namespace std;

int n, m, a[500010], last[500010], vis[500010], ans[500010];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        memset(last, 0, sizeof(last));
        memset(vis, 0, sizeof(vis));
        for (int j = i; j <= n; j++)
        {

            if (last[a[j]])
            {
                for (int k = last[a[j]]; k < j; k++)
                {
                    last[a[k]] = 0;
                    if (vis[a[k]] != 0)
						vis[a[k]]--;
                }
            }
            last[a[j]] = j;
            vis[a[j]]++;
        }
        for (int j = 1; j <= m; j++)
        {
            ans[j] += vis[j];
        }
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << ' ';

    return 0;
}


