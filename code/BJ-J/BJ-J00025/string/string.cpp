#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[200005], ans;
char c[200005];
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }
    int i = 1, j = n;
    while (i < j) {
        if (c[i] != c[j]) {
            ans += min(a[i], a[j]);
            if (a[i] == a[j]) {
                i++, j--;
            } else if (a[i] < a[j]) {
                a[j] -= a[i];
                i++;
            } else {
                a[i] -= a[j];
                j--;
            }
        } else {
            if (a[i] == a[j]) {
                i++, j--;
            } else if (a[i] < a[j]) {
                a[j] -= a[i];
                i++;
            } else {
                a[i] -= a[j];
                j--;
            }
        }
    }
    cout << ans;
    return 0;
}
