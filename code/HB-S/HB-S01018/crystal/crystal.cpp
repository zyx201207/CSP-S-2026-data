#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+7;
typedef long long ll;
ll a[N],n,m,l=1e18,r=-1e18,ans,cnt;
bool check(ll x){
    ll k=0;
    for(int i=1;i<=n;i++){
        if(a[i]<x)k+=(x-a[i]);
    }
    return k<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l=min(l,a[i]),r=max(r,a[i]);
    }
    sort(a+1,a+1+n);
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
    int x=upper_bound(a+1,a+1+n,ans)-a-1;
    for(int i=x;i>=1;i--)
        if(m-ans+a[i]>=0)cnt++,m-=(ans-a[i]);
        else break;
    cout<<cnt;
    return 0;
}
