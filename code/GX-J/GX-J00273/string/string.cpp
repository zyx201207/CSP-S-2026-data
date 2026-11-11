#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
char c[200005];
typedef long long ll;
int l = 1, r;
ll i = 1, j, ans;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    r = n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        j = a[i];
    }
    i = a[1];
    while (l <= r) {
        if (c[l] == c[r]) {
            if (i > j) {
                i -= j;
                r--;
                j = a[r];
            } else if (i == j) {
                l++;
                i = a[l];
                r--;
                j = a[r];
            } else if (i < j) {
                j -= i;
                l++;
                i = a[l];
            }
        } else {
            if (i > j) {
                ans += j;
                i -= j;
                r--;
                j = a[r];
            } else if (i == j) {
                ans += j;
                l++;
                i = a[l];
                r--;
                j = a[r];
            } else if (i < j) {
                j -= i;
                ans += i;
                l++;
                i = a[l];
            }
        }
    }
    cout << ans;
    return 0;
}
