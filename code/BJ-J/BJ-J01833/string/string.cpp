#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<char> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> c[i];
    }
    int l = 0, r = n - 1;
    long long ans = 0;
    while (l < r) {
        int cnt = a[l] - a[r];
        if (cnt > 0) {
            if (c[l] != c[r]) {
                ans += a[r];
            }
            a[l] -= a[r];
            r--;
        } else if (cnt == 0) {
            if (c[l] != c[r]) {
                ans += a[r];
            }
            l++;
            r--;
        } else if (cnt < 0) {
            if (c[l] != c[r]) {
                ans += a[l];
            }
            a[r] -= a[l];
            l++;
        }
    }
    cout << ans << '\n';

    return 0;
}
