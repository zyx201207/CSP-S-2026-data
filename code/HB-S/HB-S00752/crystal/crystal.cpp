#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5e5 + 5;

int n, m;
int a[N];
int l = 0, r = 1e18;
bool check(int x) {
    int res = 0;
    for (int i = 2; i <= x; ++i) {
        res += (i - 1) * (a[i] - a[i - 1]);
    }
    int now = res;
    for (int i = x + 1; i <= n; ++i) {
        int nd = (x - 1) * (a[i] - a[i - 1]);
        int l = i - x + 1;
        nd -= (a[i - 1] - a[l - 1]);
        nd += now;
        now = nd;
        res = min(now, res);
    }
    return res <= m;
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    l = 1, r = n;
    int ans = 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) {
            l = mid + 1;
            ans = mid;
        }else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}