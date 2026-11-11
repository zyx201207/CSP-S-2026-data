#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define drep(i, r, l) for (int i = r; i >= l; --i)
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define FRE(p) freopen(#p".in", "r", stdin), freopen(#p".out", "w", stdout)
#define eb emplace_back
#define LL long long
#define PII pair<int,int>
using namespace std;
const int N = 4005;
int n, k;
vector<int> G[N];
int ans = N;
int D, dep[N];
int bj[N];
int check() {
    queue<int> q;
    rep(i, 1, n) dep[i] = N;
    rep(i, 1, n) if (bj[i]) q.push(i), dep[i] = 0;
    int ret = 0;
    while (q.size()) {
        int x = q.front(); q.pop();
        ret = max(ret, dep[x]);
        for (int y : G[x]) if (dep[y] > dep[x] + 1) dep[y] = dep[x] + 1, q.push(y);
    }
    return ret;
}
int fa[N];
int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }
bool ok() {
    rep(i, 1, n) fa[i] = i;
    rep(i, 1, n) for (int j : G[i]) if (bj[i] && bj[j]) fa[find(j)] = find(i);
    int cnt = 0;
    rep(i, 1, n) if (fa[i] == i && bj[i]) ++cnt;
    return cnt <= 2;
}
inline void solve() {
    cin >> n >> k;
    rep(i, 2, n) {
        int u, v;
        cin >> u >> v;
        G[u].eb(v), G[v].eb(u);
    }
    ans = N;
    if (k == 2) {
        rep(i, 1, n) rep(j, i + 1, n) {
            bj[i] = 1, bj[j] = 1;
            ans = min(ans, check());
            bj[i] = bj[j] = 0;
        }
        goto end;
    }
    for (int S = 0; S < 1 << n; ++S) if (__builtin_popcount(S) == k) {
        for (int i = 0; i < n; ++i) bj[i + 1] = S >> i & 1;
        if (ok()) ans = min(ans, check());
        rep(i, 1, n) bj[i] = 0; 
    }
    end:;
    cout << ans << '\n';
    rep(i, 1, n) G[i].clear();
}
signed main() {
    FASTIO;
#ifdef LOCAL
    FRE(test);
#else
    FRE(hub);
#endif
    int tid, _;
    cin >> tid >> _;
    while (_--) solve();
    return 0;
}