#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define int long long
int arr[500005], presum[500005];
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    for (int i = 1; i <= n; i++) presum[i] = presum[i - 1] + arr[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = i;
        // printf("at %lld\n", i);
        while (l + 1 < r) { // (l, r]
            int mid = (l + r) / 2;
            // printf("(%lld, %lld] mid = %lld\n", l, r, mid);
            // printf("%lld\n", (i - mid) * arr[i] - presum[i - 1] + presum[mid - 1]);
            if ((i - mid) * arr[i] - presum[i - 1] + presum[mid - 1] <= m) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        ans = max(ans, i - r + 1);
    }
    cout << ans << '\n';
}