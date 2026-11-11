#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
vector<ll>a;
vector<ll>presum;
bool check(ll k){
    for(int i=k-1;i<n;i++){
        ll now;
        if(i==k-1)now=presum[i];
        else now=presum[i]-presum[i-k];
        if(a[i]*k-now<=m)return 1;
    }return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    a.assign(n,0);
    presum.assign(n,0);
    for(int i=0;i<=n-1;i++){
        scanf("%lld",&a[i]);
    }sort(a.begin(),a.end());
    presum[0]=a[0];
    for(int i=1;i<n;i++){
        presum[i]=a[i]+presum[i-1];
    }
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid))l=mid+1;
        else r=mid;
    }int ans=l-1;
    if(check(l))ans=l;
    if(check(l+1))ans=l+1;
    printf("%d\n",ans);
    return 0;
}