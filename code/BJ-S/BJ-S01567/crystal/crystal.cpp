#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 10;
int n, m, a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int S = 0, ans = 0;
    for (int l = 1, r = 1; r <= n; r++) {
        S += a[r];
        while (l <= r && a[r] * (r - l + 1) - S > m) {
            S -= a[l];
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
    return 0;
}
