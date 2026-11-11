#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
long long dis[5010][5010], w[5010], t[5010][5010], a[5010][5010];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dis, 127, sizeof dis);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> a[i][j] >> t[i][j];
            if (j != 1)
            {
                dis[a[i][j]][a[i][j - 1]] = 0;
            }
        }
    }
    for (int k = 1; k <= m; k++)
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = i; j <= m; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + t[i][k] + t[k][j] + dis[k][j]);
            }
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << w[x] + w[y] + dis[x][y] << '\n';
    }
    return 0;
}
