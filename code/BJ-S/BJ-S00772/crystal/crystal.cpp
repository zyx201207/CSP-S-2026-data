#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5E5 + 500;
int sum[MAXN];
int _sum[MAXN];
int a[MAXN];
int n, m, maxn = 0;
signed main () {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    //cout << n;
    for (int i = n; i >= 1; i--) {
        sum[i] = a[n] - a[i];
        _sum[i] = _sum[i + 1] + sum[i];
    }
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i;
        while (l < r) {
            int mid = (l + r) >> 1;
            if ((_sum[mid] - _sum[i] - (i - mid) * sum[i]) <= m) r = mid;
            else l = mid + 1;
        }
        maxn = max(maxn, i - l + 1);
    }
    cout << maxn;
    return 0;
}
