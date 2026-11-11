#include<bits/stdc++.h>
using namespace std;
const int M=5e5+50;
long long n,m;
long long a[M],dp[M];
long long cnt(int p,int q){
    return a[q]*(q-p+1)-(dp[q]-dp[p-1]);
}
int erfen(int x){
    int l=1,r=x,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(cnt(mid,x)<=m) r=mid;
        else l=mid+1;
    }
    return x-r+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+a[i];
    }
    int ans=1;
    for(int i=2;i<=n;i++){
        ans=max(ans,erfen(i));
    }
    printf("%d",ans);
    return 0;
}
