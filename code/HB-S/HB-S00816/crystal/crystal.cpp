#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[511111];
ll s[511111];
ll n, m, ans;

int main (){
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> m;
    if (n == 1){
        cout << "1\n";
        return 0;
    }
    for (ll i = 1; i <= n; ++i) cin >> a[i];
    sort (a+1, a+n+1);
    for (ll i = 1; i <= n; ++i){
        s[i] = s[i-1]+a[i];
    }
    ll r = 1;
    for (ll l = 1; l <= n; ++l){
        while (r<n && (a[r+1])*(r-l+2)-(s[r+1]-s[l-1]) <= m) r++;
        ans = max (ans, (ll)r-l+1);
    }
    cout << ans << "\n";


    return 0;
}
