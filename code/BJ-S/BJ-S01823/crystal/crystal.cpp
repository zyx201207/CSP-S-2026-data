#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500010],ans,q[500010];
ll zhi(ll l,ll r){
    return q[r]-q[l-1]-(a[r]-a[l-1])*(l-1);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++){
        q[i]=q[i-1]+((i-1)*(a[i]-a[i-1]));
    }
    ll l=1;
    for(ll i=1;i<=n;i++){
        while(zhi(l,i)>m)l++;
        ll x=zhi(l,i);
        //cout<<i<<' '<<l<<' '<<x<<"\n";
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
//h u a  d o n g  c h u a n g  k o u  n i u   b i  !!!
