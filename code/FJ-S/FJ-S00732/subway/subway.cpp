#include <bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
#define ll long long
const int N = 505, M = 5e5 + 5, K = 25;
int cid, n, m, d, q, w[M], c[M], o[M][K], t[M][K]; ll g[N][N];
void ckmin(ll& x, ll y) {x = (x < y ? x : y);}
int main()
{
    FILE("subway");
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> cid >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        int k; cin >> k;
        while (k--)
        {
            int a, b; cin >> a >> b;
            o[a][++c[a]] = i; t[a][c[a]] = b;
        }
    }
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= m; i++)
        for (int x = 1; x <= c[i]; x++) for (int y = x + 1; y <= c[i]; y++)
        {
            int u = o[i][x], v = o[i][y], w = t[i][x] + t[i][y];
            ckmin(g[u][v], w); ckmin(g[v][u], w);
        }
    for (int i = 1; i <= n; i++) g[i][i] = 0;
    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) 
        ckmin(g[i][j], g[i][k] + g[k][j]);
    while (q--)
    {
        int i, j; cin >> i >> j; ll ans = 1e18;
        for (int x = 1; x <= c[i]; x++) for (int y = 1; y <= c[j]; y++)
            ans = min(ans, t[i][x] + t[j][y] + g[o[i][x]][o[j][y]]);
        cout << ans + w[i] + w[j] << "\n";
    }
    return 0;
}