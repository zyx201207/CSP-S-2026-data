#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define drep(i, r, l) for (int i = r; i >= l; --i)
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define FRE(p) freopen(#p".in", "r", stdin), freopen(#p".out", "w", stdout)
#define eb emplace_back
#define LL long long
#define PII pair<int,int>
using namespace std;
const int N = 5e5+5;
int n;
LL m, a[N];
signed main() {
    FASTIO;
#ifdef LOCAL
    FRE(test);
#else
    FRE(crystal);
#endif
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    LL sum = 0;
    int l = 1, mx = 0;
    rep(i, 1, n) {
        while (l <= i && a[i] * (i - l) - sum > m) sum -= a[l++];
        mx = max(mx, i - l + 1);
        sum += a[i];
    }
    cout << mx << '\n';
    return 0;
}