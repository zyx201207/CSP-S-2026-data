#include <bits/stdc++.h>
#define int long long
using namespace std;

const int NR = 510, MR = 5e5 + 10, DR = 25, QR = 1e5 + 10;
int c, n, m, d, q, x, t;
int w[MR];
int k[NR];
struct Edge{
    int to, w;
};
vector<Edge> have[MR];
int g[NR][NR];
int dis[NR][NR];
void bellman_ford()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dis[i][j] = g[i][j];

    for(int i = 1; i <= n; i++)
    {
        for(int k = 1; k <= n; k++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >>m >> d >>q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j<= n; j++)
        {
            g[i][j] = 1e18;
            if(i == j) g[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++)
        {
            cin >> x >>t;
            for(auto y:have[x])
            {
                g[y.to][i] = min(t + y.w, g[y.to][i]);
                g[i][y.to] = min(t + y.w, g[i][y.to]);
            }
            have[x].push_back({i, t});
        }
    }
    //O(sigma(k_i) * d) = O(1e7)
    bellman_ford();
    int u, v;
    while(q--)
    {
        cin >> u >> v;
        int ans = 1e18;
        for(auto X:have[u])
        {
            for(auto Y:have[v])
            {
                ans = min({ans, X.w + Y.w + dis[X.to][Y.to], X.w + Y.w + dis[Y.to][X.to]});
            }
        }
        cout << ans + w[u] + w[v] << "\n";
    }
    return 0;
}
