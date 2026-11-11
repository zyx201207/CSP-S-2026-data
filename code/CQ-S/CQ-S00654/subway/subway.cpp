#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define drep(i, r, l) for (int i = r; i >= l; --i)
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define FRE(p) freopen(#p".in", "r", stdin), freopen(#p".out", "w", stdout)
#define eb emplace_back
#define LL long long
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 5e5+5, M = 505;
int tid, n, m, d, q;
int w[N];
int he[N], ver[N], ne[N], tim[N], tot;
inline void adde(int u, int v, int w) {
    ver[++tot] = v, tim[tot] = w, ne[tot] = he[u], he[u] = tot;
}
LL f[M][M];
signed main() {
    FASTIO;
#ifdef LOCAL
    FRE(test);
#else
    FRE(subway);
#endif
    cin >> tid >> n >> m >> d >> q;
    rep(i, 1, m) cin >> w[i];
    rep(i, 1, n) {
        int k;
        cin >> k;
        while (k--) {
            int v, t;
            cin >> v >> t;
            adde(v, i, t);
        }
    }
    memset(f, 0x3f, sizeof(f));
    rep(v, 1, m) {
        for (int i = he[v], cx, tx; i; i = ne[i]) {
            cx = ver[i], tx = tim[i];
            for (int j = he[v], cy, ty; j; j = ne[j]) {
                cy = ver[j], ty = tim[j];
                f[cx][cy] = min(f[cx][cy], (LL)tx + ty);
            }
        }
    }
    rep(i, 1, n) f[i][i] = 0;
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    rep(i, 1, q) {
        int u, v;
        cin >> u >> v;
        LL ans = f[0][0];
        for (int i = he[u], cx, tx; i; i = ne[i]) {
            cx = ver[i], tx = tim[i];
            for (int j = he[v], cy, ty; j; j = ne[j]) {
                cy = ver[j], ty = tim[j];
                ans = min(ans, (LL)tx + ty + f[cx][cy]);
            }
        }
        cout << ans + w[u] + w[v] << '\n';
    }
    return 0;
}