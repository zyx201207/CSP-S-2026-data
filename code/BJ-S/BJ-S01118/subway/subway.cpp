#include <bits/stdc++.h>
#define pii pair < int, int >
#define F first
#define S second
using namespace std;

typedef long long ll;

const int N = 500;
const int M = 5e5;

int c, n, m, d, q;

int w[M + 5];

int l[N + 5];

vector < pii > e[M + 5];

ll g[N + 5][N + 5];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    memset(g, 0x3f, sizeof(g));
    for (int i = 1 ; i <= n ; i++) g[i][i] = 0;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> w[i];
    }
    for (int v = 1 ; v <= n ; v++)
    {
        cin >> l[v];
        for (int i = 1 ; i <= l[v] ; i++)
        {
            int u, ww;
            cin >> u >> ww;
            e[u].push_back({v, ww});
        }
    }
    for (int i = 1 ; i <= m ; i++)
    {
        int siz = e[i].size();
        for (int j = 0 ; j < siz ; j++)
        {
            for (int k = j + 1 ; k < siz ; k++)
            {
                int u = e[i][j].F, v = e[i][k].F;
                ll ww = (ll)e[i][j].S + e[i][k].S;
                g[u][v] = min(g[u][v], ww);
                g[v][u] = min(g[v][u], ww);
            }
        }
    }
    for (int k = 1 ; k <= n ; k++)
    {
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = 1 ; j <= n ; j++)
            {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    while (q--)
    {
        int s, t;
        cin >> s >> t;
        ll ans = 1e18;
        int siz1 = e[s].size();
        int siz2 = e[t].size();
        for (int i = 0 ; i < siz1 ; i++)
        {
            for (int j = 0 ; j < siz2 ; j++)
            {
                int u = e[s][i].F, v = e[t][j].F;
                ll ww = e[s][i].S + e[t][j].S;
                ans = min(ans, (ll)w[s] + w[t] + ww + g[u][v]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
