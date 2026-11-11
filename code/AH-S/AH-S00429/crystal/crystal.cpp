#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define int long long
#define OI
using namespace std;

const int N = 5e5 + 10;
int n, m, ans;
int a[N], sum[N];

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef OI
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
#endif
    cin >> n >> m;
    rep (i, 1, n) cin >> a[i];
    sort (a + 1, a + n + 1);
    rep (i, 1, n) sum[i] = sum[i - 1] + a[i];
    int left = 1, right = 1;
    while (left <= right && right <= n) {
        while (abs(a[right] * (right - left + 1) - (sum[right] - sum[left - 1])) <= m && right <= n) {
            ans = max(ans, right - left + 1);
            right++;
        }
        left++;
    }
    cout << ans;
    return 0;
}
