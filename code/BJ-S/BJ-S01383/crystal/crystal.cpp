#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[500005],f[500005],m;
int n,ans = 0;

bool check(int len) {
    for (int i = len; i <= n; i++) {
        ll strt = (ll) i - len + 1;
        ll tot = f[i] - f[strt - 1];
        ll num = len * a[i] - tot;
        if (num <= m) return true;
    }
    return false;
}

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + a[i];
    int l = 1,r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) ans = mid,l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}
