#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll N=5e5+5;
ll n,k,a[N],sum[N];
ll getsum(ll l,ll r){
    return sum[r]-sum[l-1];
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    ll res=0;
    for(ll i=1;i<=n;i++){
        ll l=1,r=i,ans=i;
        while(l<=r){
            ll m=(l+r)>>1;
            if(a[i]*(i-m+1)-getsum(m,i)<=k){
                r=m-1;
                ans=m;
            }else{
                l=m+1;
            }
        }
        res=max(res,i-ans+1);
    }
    cout<<res<<"\n";
    return 0;
}