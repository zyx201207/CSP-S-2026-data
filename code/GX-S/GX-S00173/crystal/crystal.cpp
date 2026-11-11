#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5e5 + 10;
int n, flagA = 1, flagB = 1;
LL m, a[N];
void A() {
    if (!m)
        cout << 0;
    else {
        LL l = 1, r = N, x = r;
        while (l <= r) {
            LL mid = (l + r) >> 1;
            //cout << mid * (mid + 1) << ' ' << 2LL * m << '\n';
            if (mid * (mid + 1) > 2LL * m)
                r = mid - 1;
            else
                l = mid + 1, x = mid;
            //cout << mid << '\n';
        }
        cout << x + 1;
    }

}
void B() {
    LL d = a[2] - a[1];
    if (m < d)
        cout << 0;
    else {
        LL l = 1, r = N, x = r;
        while (l <= r) {
            LL mid = (l + r) >> 1;
            if (d * mid * (mid + 1) > 2LL * m)
                r = mid - 1;
            else
                l = mid + 1, x = mid;
        }
        cout << x + 1;
    }
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        flagA &= (a[i] == i);
    for (int i = 2; i < n; i++)
        flagB &= (a[i] - a[i - 1] == a[i + 1] - a[i]);
    if (flagA)
        A();
    else if (flagB)
        B();
    else {
        sort(a + 1, a + n + 1);
        if (n <= 5000) {
            int ans = 0;
            for (int i = n; i >= 1; i--) {
                LL st = a[i], sum = 0;
                int j = i - 1;
                for (; j >= 1;) {
                    if (sum + st - a[j] <= m)
                        sum += st - a[j], j--;
                    else
                        break;
                }
                ans = max(ans, i - j);
            }
            cout << ans;
        } else {
            int ans = 0, r = 1;
            LL sum = 0;
            for (int l = 1; l <= n; l++) {
                while (r < n && sum + (a[r + 1] - a[r]) * (r - l + 1) <= m) {
                    sum += (a[r + 1] - a[r]) * (r - l + 1);
                    //cout << l << ' ' << r << ": " << sum << '\n';
                    r++;
                }
                ans = max(ans, r - l + 1);
                sum -= a[r - 1] - a[l];
            }
            cout << ans;
        }
    }
    return 0;
}
