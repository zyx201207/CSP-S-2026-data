#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005],b[500005];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    if(n<=10000){
        ll ans=0;
        for(ll i=1;i<=n;i++){
            for(ll j=n;j>i;j--){
                if(a[j]*(j-i)-b[j-1]+b[i-1]<=m){
                    ans=max(ans,j-i+1);
                }
            }
        }
        cout<<ans;
    }
    else{
        for(ll i=n;i>=1;i--){
            if(a[i]*(i-1)-b[i-1]<=m){
                cout<<i;
                break;
            }
        }
    }
    return 0;
}
