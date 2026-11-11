#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5, M = 505;
int n, m, d, q, w[N], e[M][M];
vector <int> id[N], num[N];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        while (k--) {
            int a, t; cin >> a >> t;
            id[a].push_back(i), num[a].push_back(t);
        }
    }
    memset(e, 0x3f, sizeof(e));
    for (int i = 1; i <= n; i++) e[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < id[i].size(); j++)
            for (int k = j + 1; k < id[i].size(); k++) {
                int u = id[i][j], v = id[i][k],
                w = num[i][j] + num[i][k];
                e[u][v] = min(e[u][v], w), e[v][u] = e[u][v];
            }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
    while (q--) {
        int u, v, ans = 1e18; cin >> u >> v;
        for (int i = 0; i < id[u].size(); i++)
            for (int j = 0; j < id[v].size(); j++)
                ans = min(ans, w[u] + w[v] + num[u][i] +
                num[v][j] + e[id[u][i]][id[v][j]]);
        cout << ans << '\n';
    }
    return 0;
}
