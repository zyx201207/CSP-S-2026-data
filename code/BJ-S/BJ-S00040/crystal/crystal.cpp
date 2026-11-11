#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int a[N], s[N];
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i, res = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if ((i - mid) * a[i] - (s[i-1] - s[mid-1]) <= m) r = mid - 1, res = mid;
            else l = mid + 1;
        }
        //cout << l << ' ' << r << '\n';
        //cout << res << ":" << (i - res) * a[i] - (s[i-1] - s[res-1]) << "<=" << m << '\n';
        ans = max(ans, i - res + 1);
    }
    cout << ans;
    return 0;
}
//15:55
/*
liu ge cai dan
qi zhong nian ji qian 5
syh 666!!!
*/
