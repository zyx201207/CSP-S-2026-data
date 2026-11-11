
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 500005

ll n,m;
ll a[maxn],ddp[maxn],price[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    ll ans = -1;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            ddp[j]= 0;
        }
        for(ll k=1;k<=i;k++){
            price[k]=a[i] - a[k];
        }
        for(ll j=1;j<=i;j++){
            for(ll g=m;g>=price[j];g--){
                ddp[g] = max(ddp[g],ddp[g-price[j]]+1);
            }
        }
        for(ll j=1;j<=m;j++){
            ans = max(ans,ddp[j]);
        }
    }
    cout << ans/2;
    return 0;
}


