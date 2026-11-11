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

vector<vector<int>> edges(maxn);
vector<int> vis(maxn), d(maxn);
DSU ds;

void dfs (int u, int fa) {
    for (auto v : edges[u]) {
        if (v == fa) continue;
        if (vis[v] && vis[u]) ds.merge(u, v);
        cmin(d[v], d[u] + 1);
        dfs(v, u);
        cmin(d[u], d[v] + 1);
    }
}

void solve () {
    int n, k; cin >> n >> k;
    for (int i = 0; i < maxn; i++) edges[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int ans = inf;
    for (int msk = 0; msk < (1 << n); msk++) {
        if (__builtin_popcount(msk) != k) continue;
        fill(all(vis), 0);
        fill(all(d), inf);
        for (int i = 1; i <= n; i++) if ((msk >> (i - 1)) & 1) vis[i] = 1, d[i] = 0;
        
        ds.init(n + 1);

        dfs(1, 0);

        map<int, int> mp;
        for (int i = 1; i <= n; i++) if (vis[i]) mp[ds.find(i)] += 1;
        if (mp.size() > 2) continue;
        else {
            int maxx = 0;
            for (int i = 1; i <= n; i++) cmax(maxx, d[i]);
            cmin(ans, maxx);
        }
    }

    cout << ans << endl;
} 

int main () {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c, T = 1;
    cin >> c >> T;

    while (T--) {
        solve();
    }

    return 0;
}
