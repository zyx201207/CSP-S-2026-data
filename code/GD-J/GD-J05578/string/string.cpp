#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 10;
int a[N];
char c[N];

signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        s += a[i];
    }
    int x = 1, y = n, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (c[x] != c[y]) ans += min(a[x], a[y]);
        if (a[x] > a[y]) {
            a[x] -= a[y];
            a[y] = 0;
            y--;
        } else if (a[x] < a[y]) {
            a[y] -= a[x];
            a[x] = 0;
            x++;
        } else {
            a[x] = a[y] = 0;
            x++, y--;
        }
    }
    cout << ans << endl;
    return 0;
}
