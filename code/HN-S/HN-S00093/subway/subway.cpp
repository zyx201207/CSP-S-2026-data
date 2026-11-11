#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2 + 5;
const int M = 5e5 + 5;
ll dis[N][N];
vector<int> p[M];
int c, n, m, d, q, w[M], t[N][M];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1, k; i <= n; i++)
    {
        cin >> k;
        for(int j = 0, x, y; j < k; j++)
        {
            cin >> x >> y;
            t[i][x] = y;
            p[x].push_back(i);
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 1; i <= n; dis[i][i] = 0, i++);
    for(int i = 1, len; i <= m; i++)
    {
        len = p[i].size();
        for(int j = 0; j < len; j++)
        {
            for(int k = j + 1; k < len; k++)
            {
                ll res = t[p[i][j]][i] + t[p[i][k]][i];
                dis[p[i][j]][p[i][k]] = min(dis[p[i][j]][p[i][k]], res), dis[p[i][k]][p[i][j]] = min(dis[p[i][k]][p[i][j]], res);
            }
        }
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]), j++);
        }
    }
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        ll ans = 1e18;
        for(auto u : p[x])
        {
            for(auto v : p[y]) ans = min(ans, t[u][x] + t[v][y] + dis[u][v]);
        }
        cout << ans + w[x] + w[y] << "\n";
    }
    return 0;
}