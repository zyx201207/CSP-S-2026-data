#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define d(x) cout<<"# "<<x<<" ";
ll n,m,lg[500005],a[500005],sum[500005],mx[20][1000005],ans;
ll getmax(ll l,ll r){
    ll v=r-l+1;
    return max(mx[lg[v]][l],mx[lg[v]][r-(1ll<<lg[v])+1]);
}
int main(){
    ios::sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    lg[1]=0;
    memset(mx,0x80,sizeof(mx));
    for(ll i=2;i<=n;++i){
        lg[i]=lg[i>>1]+1;
    }
    for(ll i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;++i){
        sum[i]=sum[i-1]+a[i];
        mx[0][i]=a[i];
    }
    for(ll k=1;k<=lg[n];++k){
        for(ll i=1;i<=n;++i){
            mx[k][i]=max(mx[k-1][i],mx[k-1][i+(1ll<<(k-1))]);
        }
    }
    for(ll i=1;i<=n;++i){
        ll l=i,r=n+1,res=i;
        while(l<=r){
            ll mid=(l+r)>>1,len=mid-i+1;
            if(len*getmax(i,mid)<=sum[mid]-sum[i-1]+m) res=mid,l=mid+1;
            else r=mid-1;
        }
        ans=max(ans,res-i+1);
    }
    cout<<ans;
}
