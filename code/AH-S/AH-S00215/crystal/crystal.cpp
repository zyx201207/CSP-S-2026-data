#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
ll n,m,a[N],ans;
void try30(ll cz){
    m/=cz;
    ll l=1,r=m+1;
    while(l<r){
        ll mid=(l+r)/2;
        if(mid*(mid+cz)/2<=m)l=mid+1;
        else r=mid;
    }
    cout<<l;
    return ;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    ll c,sf=1;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(i==2)c=a[2]-a[1];
        if(i>2 && a[i]-a[i-1]!=c)sf=0;
    }
    if(sf){
        try30(c);
        return 0;
    }
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++){
        ll sum=0;
        for(ll j=i-1;j>=1;j--){
            sum+=a[i]-a[j];
            if(sum>m){
                ans=max(ans,i-j);
                break;
            }
        }
        if(sum<=m)ans=max(ans,i);
    }
    cout<<ans;
    return 0;
}
