#include <bits/stdc++.h>
#define int long long
#define rep(i, s, t) for (int i = s; i <= t; i++)
#define pre(i, s, t) for (int i = s; i >= t; i--)
#define pb push_back
using namespace std;
using PII = pair<int, int>;
const int N = 505, M = 5e5 + N;
int c, n, m, d, Q, w[M], f[N][N];
vector<PII> g[M];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> Q;
    rep(i, 1, m) cin >> w[i];
    rep(i, 1, n) {
        int k, x, y; cin >> k;
        rep(j, 1, k) cin >> x >> y, g[x].pb({i, y});
    }
    rep(i, 1, n) rep(j, 1, n) if (i != j) f[i][j] = 1e16;
    rep(i, 1, m) {
        for (auto x : g[i]) for (auto y : g[i]) if (x != y) {
            int u = x.first, v = y.first, w = x.second + y.second;
            f[u][v] = min(f[u][v], w);
        }
    }
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) 
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    for (int x, y; Q-- && cin >> x >> y;) {
        int res = 1e16;
        for (auto X : g[x]) for (auto Y : g[y]) {
            int u = X.first, v = Y.first;
            res = min(res, X.second + Y.second + f[u][v]);
        }
        cout << res + w[x] + w[y] << '\n';
    }
    return 0;
}