#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[505050],s[505050];
bool check(ll x){
    for(int i=1;i+x-1<=n;i++){
        ll sum=a[i+x-1]*x;//adjust to sum
        ll dis=s[i+x-1]-s[i-1];
        if(sum>dis&&sum-dis<=m){
            // cout<<"can:"<<i<<' '<<i+x-1<<'\n';
            // cout<<"maxn="<<a[i+x-1]<<" r="<<s[i+x-1]<<" l="<<s[i-1]<<'\n';
            // cout<<"sum="<<dis<<' '<<"need="<<sum<<'\n';
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    ll l=1,r=n+5,ans=-0x3f3f3f3f3f3f3f3f;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)) ans=max(ans,mid),l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}