#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],maxn,minn=0x3f;
bool check(ll x){
    ll cnt=0;
    for(ll i=1;i<x;i++) cnt+=a[x]-a[i];
    return cnt<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll l=1,r=n;
    while(l<r){
        ll mid=(l+r)/2;
        if(check(mid)) l=mid+1;
        else r=mid;
    }if(check(l)) cout<<l;
    else cout<<l-1;
    return 0;
}
