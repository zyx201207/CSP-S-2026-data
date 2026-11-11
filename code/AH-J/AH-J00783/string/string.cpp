#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int a[N], n, ans = 0;
char c[N];
signed main(void) {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n ;i++) {
        cin >> a[i] >> c[i];
    }
    int l = 1, r = n;
    while (l <= r) {
        if (c[l] != c[r]) {
            ans += min(a[l], a[r]);
        }
        if (a[l] >= a[r]) {
            a[l] -= a[r];
            r--;
        }
        else {
            a[r] -= a[l];
            l++;
        }
    }
    cout << ans;
    return 0;
}
