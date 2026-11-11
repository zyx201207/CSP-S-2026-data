#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;

constexpr int N = 2e6 + 6;

struct DSU {
    int f[N];
    void init(int n) { for (int i = 1; i <= n; i++) f[i] = i; }
    int get(int x) { return x == f[x] ? x : f[x] = get(f[x]); }
    void merge(int x, int y) { f[get(x)] = get(y); }
};

int n, k;
int dep[N];
vector<int> t[N];
bool in[N];
DSU s;

void dfs_merge(int u, int f) {
    for (int v : t[u]) {
        if (v == f) continue;
        dfs_merge(v, u);
        if (in[u] && in[v]) s.merge(u, v);
    }
}

void dfs_dis(int u, int f) {
    for (int v : t[u]) {
        if (v == f) continue;
        dep[v] = dep[u] + 1;
        dfs_dis(v, u);
    }
}

pair<bool, int> work(int st) {
    for (int i = 1; i <= n; i++) {
        in[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        if ((1 << (i - 1)) & st) {
            in[i] = 1;
        }
    }
    s.init(n);
    dfs_merge(1, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (in[i] && s.f[i] == i) {
            cnt++;
        }
    }
    if (cnt > 2) return {0, 0};
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (in[i]) continue;
        dep[i] = 0;
        dfs_dis(i, 0);
        int ret = 1e9;
        for (int j = 1; j <= n; j++) {
            if (in[j]) ret = min(ret, dep[j]);
        }
        ans = max(ans, ret);
    }
    return {1, ans};
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        t[i].clear();
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    int ans = 1e9;
    for (int st = 0; st < (1 << n); st++) {
        if (__builtin_popcount(st) == k) {
            auto ret = work(st);
            if (ret.first) ans = min(ans, ret.second);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    while (t--) solve();

    return 0;
}