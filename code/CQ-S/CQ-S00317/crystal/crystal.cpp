// test pass
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define CONTEST

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    // 如果不要第 i 颗，那么就不要这颗以后的所有
    vector<int> sum(n); sum[0] = a[0];
    for (int i = 1; i < n; i++) 
        sum[i] = sum[i - 1] + a[i];
    auto check = [&](int l, int r) -> bool {
        int c = a[r] * (r - l + 1) - sum[r] + (l > 0 ? sum[l - 1] : 0);
        return c <= m;
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // 只要前 i 颗
        int l = 0, r = i, res = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid, i)) 
                r = mid - 1, res = mid;
            else 
                l = mid + 1;
        }
        if (res == -1) continue;
        ans = max(ans, i - res + 1);
    }
    cout << ans << endl;
}
signed main() {
    #ifdef CONTEST
    #ifndef LOCAL
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    #endif
    #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;   
}
// CSP-S 2026 RP++