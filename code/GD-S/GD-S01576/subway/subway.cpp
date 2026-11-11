
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 505
#define MAXM 500005

using ll = long long;

ll INF = 0x1ffff3fff3fff3ff;

int Tid;

int n, m, d, q;
ll W[MAXM]; // hall to exit

struct Edge
{
    int u;
    ll w;
};
vector<Edge> es[MAXM];

ll e[MAXN][MAXN];

void chkmin(ll &x, ll y)
{
    x = min(x, y);
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> Tid >> n >> m >> d >> q;
    for (int i = 1; i <= n; i++)
    {
        fill(e[i] + 1, e[i] + n + 1, INF);
        e[i][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> W[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int a;
            ll t;
            cin >> a >> t;
            es[a].push_back(Edge{i, t});
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (size_t j = 0; j < es[i].size(); j++)
        {
            for (size_t k = j + 1; k < es[i].size(); k++)
            {
                int u = es[i][j].u, v = es[i][k].u;
                ll w = es[i][j].w + es[i][k].w;
                chkmin(e[u][v], w);
                chkmin(e[v][u], w);
            }
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                chkmin(e[i][j], e[i][k] + e[k][j]);
            }
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y; // x != y
        ll bas = W[x] + W[y];
        ll res = INF;
        for (size_t i = 0; i < es[x].size(); i++)
        {
            for (size_t j = 0; j < es[y].size(); j++)
            {
                chkmin(res, e[es[x][i].u][es[y][j].u] + es[x][i].w + es[y][j].w);
            }
        }
        cout << res + bas << '\n';
    }
    return 0;
}
