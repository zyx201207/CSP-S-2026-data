#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 500 + 10;
const int maxm = 5e5 + 10;
const ll inf = 1e18;
int c, n, m, d, q, w[maxm];
ll f[maxn][maxn];
vector<pair<int, int> > e[maxm];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 1, x, t; j <= k; j++)
            cin >> x >> t, e[x].emplace_back(i, t);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j) f[i][j] = inf;
    for (int i = 1; i <= m; i++)
        for (auto [x, w1] : e[i])
            for (auto [y, w2] : e[i])
                f[x][y] = min(f[x][y], (ll)w1 + w2);
    for (int k = 1; k <= n; k++)
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++)
                f[u][v] = min(f[u][v], f[u][k] + f[k][v]);
    while (q--) {
        int x, y; cin >> x >> y; ll ans = inf;
        for (auto [p1, w1] : e[x])
            for (auto [p2, w2] : e[y])
                ans = min(ans, w1 + w2 + f[p1][p2]);
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}