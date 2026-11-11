#include <bits/stdc++.h>
using namespace std;
long long hs[500005]{0},x[500005]{0},n,m;
bool check(long long k){
    long long mn=1e18,d=0;
    for(long long i=k;i<=n;++i){
        long long s=x[i]*k;
        if(mn>s-(hs[i]-hs[i-k]))d=i,mn=s-(hs[i]-hs[i-k]);
    }
    return (mn<=m);
}
int main(void){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long L,R,i;
    scanf("%lld%lld",&n,&m);
    for(i=1;i<=n;++i){
        scanf("%lld",&x[i]);
    }
    sort(x+1,x+n+1);
    for(i=1;i<=n;++i)hs[i]=x[i]+hs[i-1];
    L=0,R=n;
    while(L<R){
        long long mid=(L+R)/2+1;
        if(check(mid))L=mid;
        else R=mid-1;
    }
    printf("%lld",L);
    return 0;
}
