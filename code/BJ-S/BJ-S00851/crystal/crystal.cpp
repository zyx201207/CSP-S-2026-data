
#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
const int maxm = 5e5 + 5;
#define ll long long
ll n = 0,m = 0;
ll a[maxn];
bool check(ll x){ //now crystal sum 315275
    ll sum = 0;
    for(int i = 1;i <= n;i++){
        if(a[i] <= x) {
            sum += (x - a[i]);
            if(sum <= 0) return 0;
        }
    }
    return sum <= m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }

    //ll cnt = 0;
    //for(int i = 1;i <= n;i++) if(a[i] <= 25) cnt++;
    //cout<<cnt<<endl;


    ll l = -1e18,r = 1e18,ans = 0;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(check(mid))
        {
            ll cnt = 0;
            for(int i = 1; i<=n;i++){
                if(a[i] <= mid) cnt++;
            }
            ans = cnt;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout<<ans<<endl;
    return 0;
}
