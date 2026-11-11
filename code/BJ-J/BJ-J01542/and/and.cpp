#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[200005], l, ans = 0;
ll spow(int x, int y) {
    ll tans = 1;
    while (y--) tans *= x;
    return tans;
}
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;++i) {
        cin >> a[i];
    }
    l = 1;
    for (int p = 30;p >= 0;--p) {
        sort(a + l, a + n + 1);
        ll q = spow(2,p);
        int temp = -1;
        for (int i = l;i <= n-m+1;++i) if (a[i] >= q) {
            temp = i;
            break;
        }
        if (temp == -1) {continue;}
        ans += q;
        l = temp;
        for (int i = l;i <= n;++i) a[i] -= q;
    }
    cout << ans;
    return 0;
}
