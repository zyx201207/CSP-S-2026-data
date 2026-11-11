#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 505, M = 5e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q;
ll f[M], cnt[N];
vector<pair<int, int>> g[M + N];
ll dis[N][N];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> f[i];
    for (int i = 1; i <= n; i++) {
        cin >> cnt[i];
        for (int j = 1; j <= cnt[i]; j++) {
            int a, t;
            cin >> a >> t;
            g[m + i].push_back({a, t});
            g[a].push_back({m + i, t});
        }
    }
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        for (auto &t1 : g[i]) {
            for (auto &t2 : g[i]) {
                int u = t1.first - m, v = t2.first - m;
                ll w = t1.second + t2.second;
                if (u == v) continue;
                dis[u][v] = w;
            }
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q--) {
        int x, y;
        ll ans = inf;
        cin >> x >> y;
        if (x > y) swap(x, y);
        for (auto &t1 : g[x]) {
            for (auto &t2 : g[y]) {
                int u = t1.first - m, v = t2.first - m;
                ll w = t1.second + t2.second + f[x] + f[y];
                ans = min(ans, dis[u][v] + w);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}