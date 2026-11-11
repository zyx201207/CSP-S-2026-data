#include<bits/stdc++.h>
using namespace std;

#define MAXN 500009
#define ll long long
unsigned long long m,b[MAXN];
ll n,a[MAXN];
ll calc(ll l,ll r){
    return b[r]-b[l]-l*(a[r]-a[l]);
}
int fun(ll l,ll r,ll p){
    if(l>=r)return l;
    ll mid=(l+r)>>1;
    if(calc(mid,p)>m)return fun(mid+1,r,p);
    if(calc(mid,p)<m)return fun(l,mid,p);
    if(calc(mid,p)==m)return(mid);
}
int main(){
    //freopen("crystal4.in","r",stdin);
    //freopen("crystal4.out","w",stdout);
    cin>>n>>m;
    ll i,j,k;
    ll ans;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    b[0]=0;
    for(i=1;i<n;i++){
        b[i]=b[i-1]+i*(a[i]-a[i-1]);
    }
    ans=1;
    for(i=1;i<n;i++){
        ans=max(i-fun(0,i,i)+1,ans);
    }cout<<ans;
}
