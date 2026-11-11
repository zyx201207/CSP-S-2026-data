#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
ll a[N],sum[N]; ll n,m;
bool check(ll x) {
    for(ll i = x;i <= n;i++) {
        ll cur = a[i] * x - sum[i] + sum[i-x];
        if(cur <= m) return true;
    }
    return false;
}
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    sum[0] = 0;
    for(int i = 1;i <= n;i++) {cin >> a[i];}
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++) {sum[i] = sum[i-1] + a[i];}
    ll l = 1,r = n;
    while(l < r) {
        int mid = (l + r + 1) / 2;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l;
    return 0;
}

