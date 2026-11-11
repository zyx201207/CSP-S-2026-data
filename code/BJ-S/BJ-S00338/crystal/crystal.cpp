#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
int n, m, a[500010], s[500010];
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    int res = 0;
    for(int i = 1; i <= n; i++) {
        int l = 1, r = i, ans;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(m >= ((i - mid + 1) * a[i] - (s[i] - s[mid - 1]))) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        res = max(res, i - ans + 1);
    }
    cout << res;
    return 0;
}