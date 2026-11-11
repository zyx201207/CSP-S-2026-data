#include <bits/stdc++.h>
using namespace std;

#define int long long

int x[2000005];

int llb (int k, int n) {
    int l = 1, r = n;
    int ans = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (x[mid] > k) {
            r = mid - 1;
            ans = r;
        } else {
            l = mid + 1;
        }
    }
    return ans;
} // x[ans] <= k , ans = max(ans), == lower_bound

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("migrate3.in", "r", stdin);
    freopen("migrate3.out", "w", stdout);

    int c, t;
    cin >> c >> t;

    while (t--) {
        int n, d;
        int ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) {
            cin >> x[i];
        }
        for (int i = 1; i <= n - 3; ++i) {
            int y = x[i] + d;
            int l = llb(y, n);
            if (l - 1 == i || l - 2 < 1) {
                continue;
            }
            int r0 = llb(x[l - 2] + d, n);
            int r1 = llb(x[l - 1] + d, n);
            r0 = max(r0, l);
            if (r1 - r0 > 0) {
                ans += r1 - r0;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}

// 0 2
// 4 2
// 1 2 3 4
// 5 2
// 1 2 3 4 5


// 0 2
// 5 3
// -2 -1 0 1 2
// 6 2
// -4 -3 -2 -1 3 6