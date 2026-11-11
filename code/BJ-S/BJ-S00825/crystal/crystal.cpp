#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
int a[500010];
int sa[500010];
int n, m;
bool check(int x) {
    for(int i = x; i <= n; ++i) {
        int sum = (x - 1) * a[i] - sa[i - 1] + sa[i - x];
        if(sum <= m) return 1;
    }
    return 0;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i)
        sa[i] = sa[i - 1] + a[i];
    int l = 1, r = n, ans = 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        // cout << mid << endl;
        if(check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}
