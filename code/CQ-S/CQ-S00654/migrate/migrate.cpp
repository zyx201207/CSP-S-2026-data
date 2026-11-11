#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define drep(i, r, l) for (int i = r; i >= l; --i)
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define FRE(p) freopen(#p".in", "r", stdin), freopen(#p".out", "w", stdout)
#define eb emplace_back
#define LL long long
#define PII pair<int,int>
using namespace std;
const int N = 5005, P = 1e9 + 9;
int n, nxt[N];
LL d, a[N];
int f[N], c[N], tmp[N];
inline void solve() {
    cin >> n >> d;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) nxt[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
    LL ans = 0;
    rep(i, 1, n) {
        rep(i, 1, n) f[i] = 1e9, c[i] = 0;
        f[i] = 0, c[i] = 1;
        rep(j, i, n) if (f[j] < 1000000000) rep(k, j + 1, nxt[j]) {
            if (f[k] > f[j] + 1) f[k] = f[j] + 1, c[k] = c[j];
            else if (f[k] == f[j] + 1) c[k] = (c[k] + c[j]) % P;
        }
        rep(i, 1, n) ans += c[i] == 2;
    }
    cout << ans << '\n';
}
signed main() {
    FASTIO;
#ifdef LOCAL
    FRE(test);
#else
    FRE(migrate);
#endif
    int cid, _;
    cin >> cid >> _;
    while (_--) solve();
    return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/