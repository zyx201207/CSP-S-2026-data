#include <bits/stdc++.h>
using namespace std;

int n, m, a[500005], t, vis[300005], ans[300005], b[500005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        memset(vis, -1, sizeof(vis));
        memset(b, 0, sizeof(b));
        t = 0;
        for (int j = i; j <= n; j++)
        {
            if (vis[a[j]] == -1)
            {
                vis[a[j]] = ++t;
                b[t] = a[j];
            }
            else
            {
                for (int k = vis[a[j]] + 1; k <= t; k++)
                {
                    vis[b[k]] = -1;
                    b[k] = 0;
                }
                t = vis[a[j]];
            }
        }
        for (int j = 1; j <= m; j++)
            ans[j] += (vis[j] > 0);
    }
    for (int i = 1; i <= m; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}