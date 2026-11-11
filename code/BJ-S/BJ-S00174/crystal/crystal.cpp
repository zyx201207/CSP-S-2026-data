#include <bits/stdc++.h>
#define N 2000002
#define ll long long
using namespace std;
ll n,m,a[N],s[N],ans;
ll bs(ll i,ll x){
    ll l=1,r=i;
    while(l<=r){
        int mid=(l+r)>>1;
        if(x*(i-mid+1)-(s[i]-s[mid-1])<=m)  r=mid-1;
        else  l=mid+1;
    }
    return r+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)  cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)  s[i]=s[i-1]+a[i];
    for(ll i=1;i<=n;i++){
        if(a[i]==a[i+1])  continue;
        ll res=bs(i,a[i]);
        ans=max(ans,i-res+1);
    }
    cout<<ans<<"\n";
    return 0;
}