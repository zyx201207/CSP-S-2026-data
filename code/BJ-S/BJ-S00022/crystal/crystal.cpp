#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], c[500005], cc[500005];
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++) {
        c[i] = a[i + 1] - a[i];
    }
    int i = 1, j = 1, cnt = 0, sum = 0, ans = 1;
    while (j != n + 1) {
        sum += c[j] * ++cnt;
        cc[j] = cc[j - 1] + c[j];
        while (sum > m) {
            sum -= cc[j];
            cc[j] -= c[i];
            i++;
            cnt--;
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    cout << ans + 1 << '\n';
    return 0;
}