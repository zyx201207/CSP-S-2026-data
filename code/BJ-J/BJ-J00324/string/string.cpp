#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e8 + 10;
int a[N], ai;
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;cin >> n;
    char c1, f = 1;
    for (int i = 1;i <= n; i ++) {
        int x;cin >> x;
        char c;cin >> c;
        if (i == 1) c1 = c;
        else if (c1 != c) f = 0;
        for(int j = 1; j <= x; j ++) a[++ ai] = c;
    }
    if (f) {
        cout << 0;
        return 0;
    }
    int l = 1, r = ai, mid = ai / 2, ans = 0;
    while (l <= mid && mid + 1 <= r) {
        if (a[l] != a[r]) ans ++;
        l ++, r --;
    }
    cout << ans;
    return 0;
}
