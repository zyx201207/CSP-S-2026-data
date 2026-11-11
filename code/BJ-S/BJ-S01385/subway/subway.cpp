#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 505;
const int M = 5e5 + 10;
#define ll long long
struct node { int pos; ll t; } ;
ll w[M], dis[N][N];
vector<node> p[M];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 0, ps, t; j < k; j++) cin >> ps >> t, p[ps].push_back(node({i, t}));
    }
    for (int i = 1; i <= m; i++) for (auto u : p[i]) for (auto v : p[i]) if (u.pos != v.pos) dis[u.pos][v.pos] = min(dis[u.pos][v.pos], u.t + v.t);
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q--) {
        int u, v;
        cin >> u >> v;
        ll ans = 0x3f3f3f3f3f3f3f3f;
        for (auto x : p[u]) for (auto y : p[v]) ans = min(ans, w[u] + w[v] + x.t + y.t + dis[x.pos][y.pos]);
        cout << ans << "\n";
    }
    return 0;
}