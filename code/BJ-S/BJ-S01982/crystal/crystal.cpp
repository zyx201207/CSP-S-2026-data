#include <bits/stdc++.h>
using namespace std;
const int N=5e5+9;
typedef long long ll;
ll n,m,ans;
ll a[N],d[N],p[N];
ll check(ll x){
    ll sum=a[x]*x;
    if(sum<=d[x]+m){
        return x;
    }else{
        ll l=1,r=x,mid,s;
        while(l<=r){
            mid=(l+r)/2;
            if(a[x]*(x-mid)<=m+d[x]-d[mid]){
                s=x-mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }return s;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tmp=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(tmp==0){
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            d[i]=d[i-1]+a[i];
            if(d[i]>=1ll*10000000005){
                tmp=1;
            }
        }
        for(int i=1;i<=n;i++){
            ans=max(ans,check(i));
        }cout<<ans<<"\n";
    }else{
        ll t=a[2]-a[1];
        ll x=m/t;
        for(ll i=2;i<=n;i++){
            p[i]=i*(i-1)/2;
            if(p[i]>x){
                cout<<i-1<<"\n";
                return 0;
            }
        }
    }

return 0;
}
