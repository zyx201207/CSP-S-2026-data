#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],t[500010];
bool check(long long x){
    memset(t,0,sizeof(t));
    for(long long i=0;i<x;i++){
        t[x-1]+=a[x-1]-a[i];
    }
    for(long long i=x;i<=n;i++){
        t[i]=t[i-1]+x*(a[i]-a[i-1])-a[i]+a[i-x];
        if(t[i]<=m){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long l=1,r=n,ans=1;
    while(l<=r){
        long long mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
