#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
ll a[N], mx, mn, upd[N], ans;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, d;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i], mx = max(mx, a[i]), mn = min(mn, a[i]);
    sort(a + 1, a + n + 1);
    ll l = 1, r = 1, sum = a[1];
    while(r <= n){
        if((r - l + 1) * a[r] - sum <= m) ans = max(ans, r - l + 1), r++, sum += a[r];
        else sum -= a[l], l++;
    }
    cout << ans;
    return 0;
}