#include <bits/stdc++.h>
using namespace std;
int main () {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long n, sum = 0, ans = 0;
    cin >> n;
    vector<long long> a(n+1);
    vector<char> c(n+1);
    string str = " ";
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        sum += a[i];
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }
    int l = 1, r = n;
    while (l < r) {
        if (a[l] > a[r]) {
            if (c[l] != c[r]) {
                ans += a[r];
            }
            a[l] -= a[r];
            r--;
        } else if (a[l] < a[r]) {
            if (c[l] != c[r]) {
                ans += a[l];
            }
            a[r] -= a[l];
            l++;
        } else {
            if (c[l] != c[r]) {
                ans += a[r];
            }
            l++;
            r--;
        }
    }
    cout << ans;
    return 0;
}