#include <bits/stdc++.h> // 100 pts
using namespace std;
#define int long long
const int N = 5e5 + 2;
int n, m, a[N], ans;
bool check (int len) {
    int spre = 0;
    for (int i = 1; i < len; i++) {
        spre += a[i];
    }
    for (int l = 1; l + len - 1 <= n; l++) {
        int r = l + len - 1;
        int maxn = a[r];
        int d = (len - 1) * maxn - spre;
        if (d <= m) {
            return true;
        }
        spre -= a[l];
        spre += a[r];
    }
    return false;
}
signed main () {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 1;
    int r = n;
    int mid = (l + r) / 2;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
/*
15:21 AC
加油 JaspeHuang！
*/