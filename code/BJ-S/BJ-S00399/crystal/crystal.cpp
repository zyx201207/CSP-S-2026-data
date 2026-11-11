#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ll nowuse=0,r=0,ans=0;
    for(ll l=0;l<n;l++){
        while(r<n&&nowuse<=m){
            nowuse+=(r-l+1)*(a[r+1]-a[r]);
            r++;
        }
        r--;
        nowuse-=(r-l+1)*(a[r+1]-a[r]);
        ans=max(ans,r-l+1);
        nowuse-=a[r]-a[l];
    }cout<<ans;
    return 0;
}
