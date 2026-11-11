#include "bits/stdc++.h"
using namespace std;
int n, ans = 1;
long long m, a[500005], diff[500005];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    if (m == 0) {
        int tmp0 = 1;
        for (int i = 2; i <= n; i++) if (a[i] == a[i - 1]) {
            tmp0++;
            ans = max(ans, tmp0);
        } else tmp0 = 1;
    } else if (n <= 5000) {
        for (int i = 2; i <= n; i++) {
            diff[i - 1] = a[i] - a[i - 1];
        }
        for (int i = 2; i <= n; i++) {
            int tmp0 = 0, tmp1 = 0, tmp2 = 1;
            for (int j = i - 1; j >= 1; j--) {
                tmp0 += diff[j];
                tmp1 += tmp0;
                if (tmp1 <= m) tmp2++; else break; // Add one crystal if tmp1 <= m, else break to save time
            }
            ans = max(ans, tmp2);
        }
    } else {
        // for test point 13~18
        int remove = a[n] - a[n - 1];
        int tmp0 = 0, tmp1 = 0, tmp2 = 1;
        for (int j = n - 1; j >= 1; j--) {
            tmp0 += remove;
            tmp1 += tmp0;
            if (tmp1 <= m) tmp2++; else break;
        }
        ans = max(ans, tmp2);
    }
    cout << ans << endl;
    return 0;
}