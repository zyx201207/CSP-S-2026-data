#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll a[500005];
ll pre[500005];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a + 1, a + n + 1);
    for(ll i=2;i<=n;i++){
        pre[i] = pre[i-1] + (i-1) * (a[i] - a[i-1]);
    }
    ll l = 1;
    ll r = n;
    ll ans = 0;
    bool p = false;
    while(l <= r){
        ll mid = (l + r) / 2;
        for(ll i=1;i<=n-mid+1;i++){
            ll cnt = pre[i+mid-1] - pre[i-1] - (a[i+mid-1] - a[i-1]) * (i - 1);
            if(cnt <= m){
                p = true;
                break;
            }
        }
        if(p == true){
            p = false;
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
