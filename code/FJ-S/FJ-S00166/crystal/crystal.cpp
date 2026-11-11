#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int maxn = 5e5 + 10;
LL a[maxn], s1[maxn], s2[maxn];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    LL  n, m;
    cin >> n >> m;
    for (LL i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (LL i = 1; i <= n; i++) {
        s1[i] = s1[i - 1] + a[i];
    }
    for (LL i = n; i >= 1; i--) {
        s2[i] = s2[i + 1] + a[i];
    }
    sort(a + 1, a + n + 1);
    LL sum = 0, k = n, ans = 0;
    for (LL i = n; i >= 1; i--) {
        if (sum + (a[n] - a[i]) > m) break;
        sum += a[n] - a[i];
        ans++;
    }
    for (LL i = n - 1; i >= ans; i--) {
        LL t1 = a[k] * (k - i) - (s2[i + 1] - s2[k + 1]) + (a[k] - a[i]) * (ans - k + i);
        LL t2 = a[i] * (k - i) - (s1[k - ans] - s1[i - ans]);
        if (t1 > t2 || sum - t1 + t2 + (a[i] - a[i - ans]) <= m && t1 <= t2) {
            k = i;
            sum = sum - t1 + t2;
            if (t1 <= t2) {
                sum += a[i] - a[i - ans];
                ans++;
            }
            for (LL j = k - ans; j >= 1; j--) {
                sum += a[k] - a[j];
                ans++;
                if (sum > m) {
                    sum -= a[k] - a[j];
                    ans--;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}