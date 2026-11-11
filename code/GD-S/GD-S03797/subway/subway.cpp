#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int N = 510, M = 5e5 + 10;
int n, m, d, q, w[M];
ll f[N][N];
vector<pii> vec[M];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    IOS;
    cin >> n >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1, k; i <= n; i++) {
        cin >> k;
        for (int j = 1, a, t; j <= k; j++) {
            cin >> a >> t;
            vec[a].push_back({i, t});
        }
    }
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i++)
        f[i][i] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < vec[i].size(); j++) {
            auto [x, t] = vec[i][j];
            for (int k = j + 1; k < vec[i].size(); k++) {
                auto [y, tt] = vec[i][k];
                f[x][y] = f[y][x] = min(f[x][y], 1ll * t + tt);
            }
        }
    for (int mid = 1; mid <= n; mid++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][mid] + f[mid][j]);
    for (int i = 1, u, v; i <= q; i++) {
        cin >> u >> v;
        ll tmp = 1e18;
        for (auto [x, t] : vec[u])
            for (auto [y, tt] : vec[v])
                tmp = min(tmp, 1ll * t + tt + f[x][y]);
        cout << 1ll * w[u] + w[v] + tmp << "\n";
    }
    return 0;
}