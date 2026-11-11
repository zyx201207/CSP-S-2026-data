#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int n, k, fa[N], dep[N], f[N];
vector<int> e[N];

struct edge {
    int u, v;
} g[N << 1];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) fa[x] = y;
}

void dfs(int x, int p) {
    f[x] = p, dep[x] = dep[p] + 1;
    for (auto i : e[x]) if (i != p) dfs(i, x);
}
int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    while (dep[x] != dep[y]) x = f[x];
    while (x != y) x = f[x], y = f[y];
    return x;
}
int dist(int x, int y) {
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}

void solve() {
    cin >> n >> k;
    for (int i = 1, u, v; i < n; i ++ )
        cin >> u >> v, e[u].push_back(v), e[v].push_back(u), g[i] = {u, v};
    
    dfs(1, 0);

    int mn = n;
    
    for (int i = 0; i < 1 << n; i ++ ) {
        for (int j = 1; j <= n; j ++ ) fa[j] = j;
        if (__builtin_popcount(i) != k) continue;
        for (int j = 1; j < n; j ++ ) {
            int u = g[j].u, v = g[j].v;
            if ((i & (1 << u - 1)) && (i & (1 << v - 1))) merge(u, v);
        }
        int cnt = 0;
        for (int j = 1; j <= n; j ++ )
            if ((i & (1 << j -1)) && find(j) == j) cnt ++;
        if (cnt > 2) continue;
        int _ = 0;
        for (int j = 1; j <= n;j ++ ) {
            int __ = n;
            for (int k = 1; k <= n; k ++ ) {
                if (!(i & (1 << k - 1))) continue;
                __ = min(__, dist(j, k));
            }
            _ = max(_, __);
        }
        mn = min(mn, _);
    }

    cout << mn << '\n';

    for (int i = 1; i <= n; i ++ ) f[i] = dep[i] = 0, e[i].clear();
}

int main() {

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int c, T; cin >> c >> T;
    while (T -- ) solve();

    return 0;
}