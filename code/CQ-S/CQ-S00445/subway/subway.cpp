#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define db double
#define i128 __int128_t

#define endl "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>

#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()

using namespace std;

template <class T> void cmax (T &a, T b) {a = max(a, b); }
template <class T> void cmin (T &a, T b) {a = min(a, b); }

const int inf = 1e9;
const ll INF = 2e18;
const int mod = 1e9 + 7;
const db eps = 1e-6;
const int maxn = 1e5 + 7;
const int N = 1e6 + 7;

class DSU {
    public :
        vector<int> fa;
        int n;

        void init (int n_) {
            n = n_;
            fa.resize(n + 1);
            iota(all(fa), 0);
        }

        int find (int x) {
            if (fa[x] != x) fa[x] = find(fa[x]);
            return fa[x];
        }

        void merge (int u, int v) {
            u = find(u), v = find(v);
            if (u == v) return;
            fa[v] = u;
        }
} ;

struct Node {
    int u, v, w;
} ;

vector<vector<int>> fa(N + 1, vector<int>(22, 0));
vector<ll> sum(N + 1, 0), dep(N + 1, 0);
vector<vector<pii>> edges(N + 1);

void dfs (int u) {
    dep[u] = dep[fa[u][0]] + 1;
    for (auto tmp : edges[u]) {
        auto v = tmp.first, w = tmp.second;
        if (v == fa[u][0]) continue;
        fa[v][0] = u;
        sum[v] = sum[u] + w;
        dfs(v);
    }
}

int LCA (int u, int v){
    if (dep[u] < dep[v]) swap(u, v);
    while (dep[u] > dep[v]) u = fa[u][__lg(dep[u] - dep[v])];
    if (u == v) return u;
    for (int j = 21; j >= 0; j--) if (fa[u][j] != fa[v][j]) u = fa[u][j], v = fa[v][j];
    return fa[u][0];
}

void solve () {
    int c, n, m, d, q; cin >> c >> n >> m >> d >> q;
    vector<ll> w(m + 1);
    for (int i = 1; i <= m; i++) cin >> w[i];
    int s = m + n;
    vector<Node> E;
    for (int i = 1; i <= n; i++) {
        int now = m + i;
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int v, w; cin >> v >> w;
            E.push_back({now, v, w});
        }
    }

    DSU ds;
    ds.init(s);

    sort(all(E), [] (auto &u, auto &v) {
        return u.w < v.w;
    }) ;
    
    for (auto &tmp : E) {
        auto u = tmp.u, v = tmp.v, w = tmp.w;
        if (ds.find(u) == ds.find(v)) continue;
        ds.merge(u, v);
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    } 

    dfs(1);

    for (int j = 1; j < 22; j++) for (int i = 1; i <= s; i++) fa[i][j] = fa[fa[i][j - 1]][j - 1];

    while (q--) {
        int u, v; cin >> u >> v;
        ll ans = w[u] + w[v];
        int lca = LCA(u, v);
        ans += sum[u] + sum[v] - 2 * sum[lca];
        cout << ans << endl;
    }
} 

int main () {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
