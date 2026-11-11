#include <bits/stdc++.h>
#include <cassert>

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

const int MAXN = 510, MAXM = 5e5 + 10;

int n, m, d, q;
int w[MAXM];
ll f[MAXN][MAXN];
vector <pair <int, int>> e[MAXM];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int cid;
    cin >> cid >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        int k; cin >> k;
        for (int j = 1, a, t; j <= k; j++)
            cin >> a >> t, e[a].emplace_back(i, t);
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < e[i].size(); j++)
            for (int k = j + 1; k < e[i].size(); k++)
                f[e[i][j].first][e[i][k].first] = 
                f[e[i][k].first][e[i][j].first] =
                min(f[e[i][j].first][e[i][k].first],
                (ll)e[i][j].second + e[i][k].second);
    }
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    int u, v;
    while (q--)
    {
        cin >> u >> v;
        ll ans = 1e18;
        for (int i = 0; i < e[u].size(); i++)
            for (int j = 0; j < e[v].size(); j++)
                ans = min(ans, (ll)e[u][i].second + e[v][j].second + f[e[u][i].first][e[v][j].first]);
        cout << ans + w[u] + w[v] << '\n';
    }
    return 0;
}