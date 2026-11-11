#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[500005];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long l = 1, r = i;
        long long cnt = 0;
        while (l < r) {
            long long mid = (l + r) / 2;
            long long midvalue = (i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]);
            if (midvalue <= m) {
                r = mid;
                cnt = i - mid + 1;
            } else {
                l = mid + 1;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
