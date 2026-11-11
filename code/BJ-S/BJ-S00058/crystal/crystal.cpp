#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans=1;
ll a[500005],p[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++)p[i]=a[i]+p[i-1];
    for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                ans=max(i-j-1,ans);
            }
    }
    cout<<ans;
    return 0;
}