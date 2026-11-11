#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
#define int long long
int n, m, a[N], pre[N];

bool check(int mid) {
    int mi = LLONG_MAX;
    for(int i = mid;i <= n;i ++) {
        mi = min(mi, a[i] * mid - (pre[i] - pre[i - mid]));
    }
    return mi <= m;
}

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1;i <= n;i++) pre[i] = pre[i - 1] + a[i];
    int l = 1, r = n, ans = 0;
    while(l <= r) {
        int mid = l + r >> 1;
        if(check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}
/*
5 8
-3 -1 2 2 7
*/
