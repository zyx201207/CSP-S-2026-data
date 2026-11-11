#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[500005],s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    LL n,m,xn=0,l=1;scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n;++i)scanf("%lld",a+i);
    sort(a+1,a+n+1);
    for(LL i=1;i<=n;++i){
        s[i]=s[i-1]+a[i];
        while(l<=n&&a[i]*(i-l+1)-s[i]+s[l-1]>m)++l;
        xn=max(xn,i-l+1);
    }
    printf("%lld",xn);
    return 0;
}
