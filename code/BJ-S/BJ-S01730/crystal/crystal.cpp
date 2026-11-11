#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0;i < n;i ++) cin >> a[i];
    sort(a.begin(),a.end());
    ll cur = 1;
    while (1){
        ll dif = abs(a[cur]-a[cur-1]) * cur;
        if (dif < m){
            m -= dif;cur ++;continue;
        }
        else if (dif == m){
            cout << cur + 1;return 0;
        }   
        else{
            cout << cur;return 0;
        }
    }
    return 0;
}