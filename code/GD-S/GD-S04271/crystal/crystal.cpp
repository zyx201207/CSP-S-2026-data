#include <bits/stdc++.h>
#define N 500005
#define fi first
#define se second
#define it(a, n) a.begin() + 1, a.begin() + (n) + 1
#define int long long
#define pii pair <int, int>
#define rep(i, s, t) for (int i = (s); i <= (t); i += 1)
using namespace std;
int n, m, ans = 0;
array <int, N> a, sum;
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    rep(i, 1, n)
        cin >> a[i];
    sort(it(a, n));
    rep(i, 1, n)
        sum[i] = sum[i - 1] + a[i];
    rep(i, 1, n) {
        int l = 1, r = i, mid = (l + r) >> 1, res;
        while (l <= r) {
            if ((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m) {
                res = mid;
                r = mid - 1;
            } else
                l = mid + 1;
            mid = (l + r) >> 1;
        }
        ans = max(ans, i - res + 1);
    }
    cout << ans << "\n";
    return 0;
}