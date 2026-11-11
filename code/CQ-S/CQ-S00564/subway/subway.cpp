#include<bits/stdc++.h>
#define LL long long
#define PLL pair<LL, LL>
#define PLI pair<LL, int>
#define PIL pair<int, LL>
#define PII pair<int, int>
using namespace std;
const LL inf = 1e18;
const int N = 500, M = 5e5;
int n, m, d, q;
LL cst[M + 5], dis[N + 5][N + 5];
vector<PLI> g[M + 5];
void get() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][j] > dis[i][k] + dis[k][j]) dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }
}

inline void solve() {
    cin >> n >> m >> d >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) dis[i][j] = inf;
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int i = 1; i <= m; i++) cin >> cst[i];
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int v; LL t; cin >> v >> t;
            g[v].push_back({t, i});
        }
    }
    for (int i = 1; i <= m; i++) {
        for (auto u : g[i]) {
            for (auto v : g[i]) {
                dis[u.second][v.second] = min(dis[u.second][v.second], u.first + v.first);
            }
        }
    }
    get();
    for (int i = 1; i <= q; i++) {
        int a, b; cin >> a >> b;
        LL ans = inf;
        for (auto j : g[a]) {
            int u = j.second; LL x = j.first;
            for (auto k : g[b]) {
                int v = k.second; LL y = k.first;
                ans = min(ans, dis[u][v] + x + y);
            }
        }
        ans += cst[a] + cst[b];
        cout << ans << "\n";
    }
}
signed main() {
    // freopen("subway7.in", "r", stdin);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int cc, tt = 1;
    cin >> cc;
    //cin >> tt;
    while (tt--) solve();
    return 0;
}