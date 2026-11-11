#include <bits/stdc++.h>
#define fi first
#define se second
#define vt vector
#define it(a, n) a.begin() + 1, a.begin() + (n) + 1
#define INF 5000000
#define int long long
#define pii pair <int, int>
#define rep(i, s, t) for (int i = (s); i <= (t); i += 1)
using namespace std;
int c;
struct Graph{
    vt <vt <int>> edge;
    Graph(int n) {
        edge.assign(n + 1, vt <int> ());
    }
    void add(int u, int v) {
        edge[u].push_back(v);
    }
};
void solve() {
    int n, d;
    cin >> n >> d;
    vt <int> x(n + 1);
    rep(i, 1, n)
        cin >> x[i];
    if (c == 11 || c == 12) {
        int D = x[2] - x[1];
        if (d < 2 * D)
            cout << 0 << "\n";
        else
            cout << max(n - (2 * (d / D) - 1), 0LL) << "\n";
        return ;
    }
    vt <int> in(n + 1, 0);
    Graph g(n);
    rep(u, 1, n)
        rep(v, u + 1, n)
            if (x[v] - x[u] <= d) {
                g.add(u, v);
                in[v] += 1;
            }
    vt <vt <pii>> f(n + 1, vt <pii> (n + 1, {INF, 0}));
    rep(i, 1, n)
        f[i][i] = {0, 1};
    queue <int> q;
    rep(i, 1, n)
        if (!in[i])
            q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g.edge[u]) {
            rep(i, 1, n) {
                if (f[i][u].fi + 1 == f[i][v].fi)
                    f[i][v].se += f[i][u].se;
                else if (f[i][u].fi + 1 < f[i][v].fi)
                    f[i][v] = {f[i][u].fi + 1, f[i][u].se};
            }
            if (!(-- in[v]))
                q.push(v);
        }
    }
    int ans = 0;
    rep(u, 1, n)
        rep(v, u + 1, n)
            ans += f[u][v].se == 2;
    cout << ans << "\n";
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> c >> t;
    while (t --)
        solve();
    return 0;
}