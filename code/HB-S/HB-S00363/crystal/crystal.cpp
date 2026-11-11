#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],sum[500005],ans,l=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(ll r=1;r<=n;r++){
        while(l<r&&sum[r-1]-sum[l-1]+m<a[r]*(r-l)) l++;
        if(sum[r-1]-sum[l-1]+m>=a[r]*(r-l)) ans=max(r-l+1,ans);
    }
    cout<<ans;
    return 0;
}
