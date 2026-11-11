#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

long long w[500010], a[500010], t[500010], d[5010][5010], g1[5010][5010];

struct stu
{
    long long v, w;
};
vector<stu> g2[500010];

void spfa(long long s)
{
    queue<long long> q;
    q.push(s);
    d[s][s] = 0;
    while (!q.empty())
    {
        long long u = q.front();
        q.pop();
        for (auto [v, w] : g2[u])
        {
            if (d[s][u] + w < d[s][v])
            {
                d[s][v] = d[s][u] + w;
                q.push(v);
            }
        }
    }
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(g1, 0x3f, sizeof g1);
    memset(d, 0x3f, sizeof d);
    long long c, n, m, b, q;
    cin >> c >> n >> m >> b >> q;
    for (long long i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (long long i = 1, k; i <= n; i++)
    {
        cin >> k;
        for (long long j = 1; j <= k; j++)
        {
            cin >> a[j] >> t[j];
        }
        for (long long x = 1; x <= k; x++)
        {
            for (long long y = 1; y <= k; y++)
            {
                if (x == y)  continue;
                g1[a[x]][a[y]] = min(g1[a[x]][a[y]], t[x] + t[y]);
            }
        }
    }
    for (long long i = 1; i <= m; i++)
    {
        for (long long j = 1; j <= m; j++)
        {
            if (g1[i][j] < 1e17)  g2[i].push_back({j, g1[i][j]});
        }
    }
    for (long long i = 1; i <= m; i++)
    {
        spfa(i);
    }
    for (long long i = 1, l, r; i <= q; i++)
    {
        cin >> l >> r;
        cout << w[l] + w[r] + d[l][r] << endl;
    }
    return 0;
}