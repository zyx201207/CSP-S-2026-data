#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 5;
int n, ans;
ll a[N], m, s[N];

int main () {
    ios::sync_with_stdio(false);
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = i, p = i;
        while (l <= r) {
            int mid = l + r >> 1;
            if ((i - mid + 1) * a[i] - s[i] + s[mid - 1] <= m) p = mid, r = mid - 1;
            else l = mid + 1;
        }
        ans = max(ans, i - p + 1);
    }
    cout << ans << '\n';
    return 0;
}
