#include <bits/stdc++.h>
#define FILE(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e6 + 5;
int n, k, dist[N], tag[N];
vector<int> g[N];
struct DSU {
    int fa[N];
    void clear(void) {
        for (int i = 0; i < N; ++i) fa[i] = i;
    }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    void merge(int x, int y) { fa[find(x)] = find(y); }
}dsu;
void solve(void) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) g[i].clear();
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 1e9;
    for (int msk = 0; msk < (1 << n); ++msk) {
        if (__builtin_popcount(msk) == k) {
            for (int i = 0; i < n; ++i) {
                tag[i + 1] = 0;
                if (msk >> i & 1) {
                    tag[i + 1] = 1;
                }
            }
            dsu.clear();
            for (int i = 1; i <= n; ++i) {
                if (tag[i]) {
                    for (int j : g[i]) {
                        if (tag[j]) dsu.merge(i, j);
                    }
                }
            }
            vector<int> tmp;
            for (int i = 1; i <= n; ++i) {
                if (tag[i]) tmp.push_back(dsu.find(i));
            }
            sort(tmp.begin(), tmp.end());
            tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
            if (tmp.size() != 2) continue;
            queue<int> q;
            for (int i = 1; i <= n; ++i) {
                if (tag[i]) {
                    q.push(i);
                    dist[i] = 0;
                }
                else dist[i] = -1;
            }
            int ret = 0;
            while (q.size()) {
                int u = q.front();
                q.pop();
                for (auto v : g[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                        ret = max(ret, dist[v]);
                    }
                }
            }
            ans = min(ans, ret);
        }
    }
    cout << ans << '\n';
}
int main() {
    FILE("hub");
    FASTIO;
    int testid, t;
    cin >> testid >> t;
    while (t--) solve();
    return 0;
}
/*
冲 T3 没冲出来，济济了

AFOed

By To_string (uid=846303)
*/