#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 5;
int n, m, a[N], b[N], s[N];
int calc(int l, int r) {
    return (r - l + 1) * a[r] - (s[r] - s[l - 1]);
}

signed main() {
    freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1); int ans = 0;
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        int l = i, r = n, p = i - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (calc(i, mid) <= m) l = mid + 1, p = mid;
            else r = mid - 1;
        } ans = max(ans, p - i + 1);
    } cout << ans;
    return 0;
}