#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
const int K = 2e1;
const int M = 2e1 + 10;
vector<int> adj[N];
int c, T, n, k, dep[N], s[M][N];
struct Dsu {
    int fth[N];
    void init() {
        for (int i = 1; i <= n; i++) fth[i] = i; 
    }
    int findset(int u) {
        return (fth[u] == u ? u : fth[u] = findset(fth[u]));
    }
    void merge(int u, int v) {
        u = findset(u), v = findset(v);
        if (u != v) fth[u] = v;
    }
} dsu;

void dfs(int u, int p) {
    dep[u] = dep[s[0][u] = p] + 1;
    for (int i = 1; i <= K; i++) s[i][u] = s[i - 1][s[i - 1][u]]; 
    for (auto v : adj[u]) if (v != p) dfs(v, u);
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = K; i >= 0; i--) if (dep[s[i][u]] >= dep[v]) u = s[i][u];
    if (u == v) return u;
    for (int i = K; i >= 0; i--) if (s[i][u] != s[i][v]) u = s[i][u], v = s[i][v];
    return s[0][u];
}

void clear() {
    for (int i = 1; i <= n; i++) adj[i].clear();
}

int calc(int u, int v) {
    return dep[u] + dep[v] - (dep[lca(u, v)] << 1);
}

void solve() {
    clear();
    cin >> n >> k;
    for (int i = 1, u, v; i <= n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    dfs(1, 0);
    int ans = n + 1;
    for (int S = 0; S <= (1 << n) - 1; S++) {
        if (__builtin_popcount(S) != k) continue;
        dsu.init();
        for (int i = 1; i <= n; i++) for (auto j : adj[i]) if (((S >> (i - 1)) & 1) && ((S >> (j - 1)) & 1)) dsu.merge(i, j); 
        vector<int> vec;
        for (int i = 1; i <= n; i++) if ((S >> (i - 1)) & 1) vec.push_back(i);
        int cnt = 0;
        for (auto i : vec) if (dsu.findset(i) == i) cnt++;
        if (cnt > 2) continue; 
        int val = 0;
        for (int i = 1; i <= n; i++) {
            int now = n + 1;
            for (auto j : vec) now = min(now, calc(i, j));
            val = max(val, now);
        }
        ans = min(ans, val);
    }
    cout << ans << "\n";
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> c >> T;
    while (T--) solve();
    return 0;
}