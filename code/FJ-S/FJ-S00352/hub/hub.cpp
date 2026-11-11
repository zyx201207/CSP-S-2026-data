#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

const int N = 1010;

int n, k, ans, col[N], dis[N][N];
std::vector<int> gr[N];

int dfs(int u, int fa, int rt) {
    int res = 1;
    for (int v : gr[u]) if (v != fa && col[v] == col[rt]) {
        res += dfs(v, u, rt);
    }
    return res;
}

int dfs2(int u, int fa) {
    int d = 1;
    for (int v : gr[u]) if (v != fa && !col[v]) {
        d = std::max(d, dfs2(v, u) + 1);
    }
    return d;
}

void doit(int i) {
    if (i == n + 1) {
        int cnt[3] {}, vis[3] {};
        for (int j = 1; j <= n; j++) cnt[col[j]]++;
        if (cnt[1] + cnt[2] != k) return;
        int sum = 0;
        for (int j = 1; j <= n; j++) if (col[j] && !vis[col[j]]) {
            vis[col[j]] = 1;
            sum += dfs(j, 0, j);
        }
        if (sum != k) return;
        int tmp = 0;
        for (int j = 1; j <= n; j++) if (!col[j]) tmp = std::max(tmp, dfs2(j, 0));
        ans = std::min(ans, tmp);
        return;
    }
    for (int c : {0, 1, 2}) {
        col[i] = c;
        doit(i + 1);
    }
}

void solve() {
    cin >> n >> k;
    ans = n;
    for (int i = 1; i <= n; i++) gr[i].clear();
    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    doit(1);
    cout << ans << "\n";
}

void dfs3(int u, int fa, int rt) {
    for (int v : gr[u]) if (v != fa) {
        dis[rt][v] = dis[rt][u] + 1;
        dfs3(v, u, rt);
    }
}

void solve2() {
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        solve();
        // if (n > 10) solve2();
    }
}