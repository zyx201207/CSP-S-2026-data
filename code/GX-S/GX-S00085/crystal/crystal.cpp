#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+7,INF=1e18+7;
ll n,m,a[N],ans,sum[N];
bool check(ll x){
    ll minv=INF;
    for(int i=1;i<=n-x+1;i++){
        ll res=0;
        res=(x-1)*a[i+x-1]-(sum[i+x-2]-sum[i-1]);
        minv=min(res,minv);
    }
    return minv<=m;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    ll l=1,r=n;
    while(l<r){
        ll mid=l+r>>1;
        if(check(mid)){
            ans=max(mid,ans);
            l=mid+1;
        }else r=mid;
    }
    cout<<ans<<endl;
    return 0;
}
