#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main()
{
#ifndef QWQ
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
#endif
    cin.tie(0)->sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector<int> w(m + 1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> w[i];
    }
    vector<vector<array<int, 2>>> f(m + 1);
    for (int i = 1, k, x, t; i <= n; ++i)
    {
        cin >> k;
        for (int j = 0; j < k; ++j)
        {
            cin >> x >> t;
            f[x].push_back({i, t});
        }
    }
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, 1e18));
    for (int i = 1; i <= n; ++i)
    {
        dis[i][i] = 0;
    }
    for (int u = 1; u <= m; ++u)
    {
        int siz = f[u].size();
        for (int i = 0; i < siz; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                dis[f[u][i][0]][f[u][j][0]] = min(dis[f[u][i][0]][f[u][j][0]], f[u][i][1] + f[u][j][1]);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dis[i][j] = min(dis[i][j], dis[j][i]);
        }
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int x, y; q--;)
    {
        cin >> x >> y;
        int ans = 1e18;
        for (auto [u, du] : f[x])
        {
            for (auto [v, dv] : f[y])
            {
                ans = min(ans, dis[u][v] + w[x] + w[y] + du + dv);
            }
        }
        cout << ans << '\n';
    }
    cerr << clock() << '\n';

    return 0;
}
/*
15:06 start T2
15:21 TL 11s
15:35 AC yangli shang WC !!!
15:39 finish WC
15:48 no worries
*/
/*
T2: 题目理清了，线路少，站多，有度数限制且极小，很明显有并查集，没有 24，25 的 sub

应该是先计算出任意两条线路切换的代价直接输出 w[x] + w[y] + d^2

fastio!!!

预估 20 min to 15：28

需要检查一下如何 n^2T() 求任意两条线路切换的代价。

发现这个复杂度有点大 $n(n+m)log(n+m)$，首先不能有 log，预计 10 min to 15：38

猜测是 md^2

过了阳历，上厕所

先测个极限数据，大概 5min to 15：45

*/