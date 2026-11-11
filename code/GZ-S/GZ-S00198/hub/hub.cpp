// 贵阳市第一中学 林钰涵 GZ-S00198
#include <bits/stdc++.h>
using namespace std;

int testid, n, m, ans, d[15][15];
bool a[15], vis[15];
vector<int> vc, e[15];

void dfs(int u, int d[]) {
    for (int& v : e[u]) {
        if (d[v] == -1) {
            d[v] = d[u] + 1;
            dfs(v, d);
        }
    }
}

void dfs2(int u) {
    for (int& v : e[u]) {
        if (a[v] && !vis[v]) {
            vis[v] = true;
            dfs2(v);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        e[i].clear();
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = -1;
        }
        d[i][i] = 0;
        dfs(i, d[i]);
        a[i] = (n - i + 1 <= m);
    }
    ans = n;
    do {
        int c = 0;
        vc.clear();
        for (int i = 1; i <= n; i++) {
            vis[i] = false;
            if (a[i]) vc.emplace_back(i);
        }
        for (int& i : vc) {
            if (!vis[i]) {
                ++c;
                if (c > 2) break;
                dfs2(i);
            }
        }
        if (c > 2) continue;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int val = n;
            for (int& j : vc) {
                val = min(val, d[i][j]);
            }
            res = max(res, val);
        }
        ans = min(ans, res);
    } while (next_permutation(a + 1, a + n + 1));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int _;
    for (cin >> testid >> _; _; --_) {
        solve();
    }
    return 0;
}
