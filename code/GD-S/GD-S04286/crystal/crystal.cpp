#include <bits/stdc++.h>
#define int long long
#define rep(i, s, t) for (int i = s; i <= t; i++)
#define pre(i, s, t) for (int i = s; i >= t; i--)
using namespace std;
const int N = 5e5 + 2;
int n, m, res, a[N], b[N];
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    rep(i, 1, n) b[i] = b[i - 1] + a[i];
    int p = 0;
    rep(i, 1, n) {
        while (p < i && a[i] * (i - p - 1) - (b[i - 1] - b[p]) > m) p++;
        res = max(res, i - p);
    }
    cout << res << '\n';
    return 0;
}