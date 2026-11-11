#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int N = 5e5+5;
int c, n, m, d, q, w[N], k, x, t, y, f[505][505];
vector<pair<int, int> > v[N];

inline int read()
{
    int f = 1, x = 0;
    c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + (c - 48);
        c = getchar();
    }
    return f * x;
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read(), n = read(), m = read(), d = read(), q = read();
    for (int i = 1; i <= m; ++i) w[i] = read();
    for (int i = 1; i <= n; ++i)
    {
        k = read();
        for (int j = 1; j <= k; ++j)
        {
            x = read(), t = read();
            v[x].push_back({i, t});
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            f[i][j] = (i == j)?0:2e18;
    for (int i = 1; i <= m; ++i)
        for (int j = 0; j < v[i].size(); ++j)
            for (int k = j+1; k < v[i].size(); ++k)
            {
                int p1 = v[i][j].first, p2 = v[i][k].first, t1 = v[i][j].second, t2 = v[i][k].second;
                f[p1][p2] = f[p2][p1] = min(f[p1][p2], t1+t2);
            }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
    while (q--)
    {
        x = read(), y = read();
        int ans = 9e18;
        for (auto e1:v[x])
            for (auto e2:v[y])
            {
                int p1 = e1.first, p2 = e2.first, t1 = e1.second, t2 = e2.second;
                ans = min(ans, w[x]+w[y]+f[p1][p2]+t1+t2);
            }
        cout << ans << '\n';
    }
    return 0;
}
