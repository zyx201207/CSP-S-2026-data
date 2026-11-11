#include<iostream>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;
int n,m,a[500010];
bool check(ll t){
    if(t==1) return true;
    ll sum=0,l=1,r=2;
    for(;r<=t;r++){
        sum+=(a[r]-a[r-1])*(r-1);
    }
    if(sum<=m) return true;
    for(;r<=n;r++){
        sum-=(a[r-1]-a[r-t]);
        sum+=(a[r]-a[r-1])*(t-1);
        if(sum<=m) return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    ll l=1,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
