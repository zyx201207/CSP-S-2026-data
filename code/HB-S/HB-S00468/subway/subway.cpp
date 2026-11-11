#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[500005], a[200][500005], t[200][500005], k[200], x, y, ans;

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &m, &n, &d, &q);
    for (int i = 1; i <= m; i++)
        scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k[i]);
        for (int j = 1; j <= k[i]; j++)
            scanf("%d%d", &a[i][j], &t[i][j]);
    }
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &x, &y);
        ans = 0;
        ans += (w[x] + w[y]);
        printf("%d\n", ans);
    }
    return 0;
}