#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],pre[500005],ans=1;
bool check(ll x,ll r){
    ll len=r-x+1;
    ll res=len*a[r]-(pre[r]-pre[x-1]);
    //cout<<x<<" "<<r<<" "<<res<<endl;
    return res<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
        ll l=1,r=i,cnt=i;
        while(l<=r){
            ll mid=(l+r)/2;
            if(check(mid,i)){
                cnt=mid;
                r=mid-1;
            }else l=mid+1;
        }
        ans=max(ans,i-cnt+1);
    }
    cout<<ans<<endl;
    return 0;
}
