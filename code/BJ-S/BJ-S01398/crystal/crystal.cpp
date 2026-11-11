#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005],cf[500005],pre[500005];
void init(){
    for(ll i=1;i<=500000;i++)pre[i]=9e18;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,k,maxn=0;
    cin>>n>>k;
    init();
    bool flag1=true,flag2=true;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)flag1=false;
        if(i>2 && a[i]-a[i-1]!=a[i-1]-a[i-2])flag2=false;
    }
    sort(a+1,a+n+1);
    if(n<=5000){
        for(ll i=1;i<=n;i++){
            cf[i]=a[i]-a[i-1];
        }
        for(ll i=1;i<=n;i++){
            for(ll j=i;j<=n;j++){
                pre[j]=min(pre[j],pre[j-1]+cf[j]*(j-1));
            }
        }
        ll ans=upper_bound(pre+1,pre+n+1,k)-(pre+1);
        cout<<ans<<'\n';
        return 0;
    }else{
        if(flag1 || flag2){
            for(ll i=1;i<=n;i++){
                cf[i]=cf[i-1]+a[i];
            }
            ll ans=upper_bound(cf+1,cf+n+1,k)-cf;
            cout<<ans<<'\n';
            return 0;
        }
    }

    return 0;
}