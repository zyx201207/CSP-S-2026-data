#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[2000005],d[5005],d2[5005],d3[5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    LL id,t;scanf("%lld%lld",&id,&t);
    for(LL _=1;_<=t;++_){
        LL n,m,c=0;scanf("%lld%lld",&n,&m);
        if(n==1){
            printf("0\n");
            continue;
        }
        for(LL i=1;i<=n;++i)scanf("%lld",a+i);
        if(id<=10){
            for(LL i=1;i<=n;++i){
                for(LL j=i;j<=n;++j)d[j]=d2[j]=d3[j]=0x3f3f3f3f3f3f3f3fll;
                d[i]=0;
                for(LL j=i+1;j<=n;++j){
                    LL l=lower_bound(a+i,a+j,a[j]-m)-a;
                    if(l<j){
                        d[j]=d[l]+1;
                        d2[j]=d2[l]+1;
                        d3[j]=d3[l]+1;
                        if(l<j-1){
                            d2[j]=min(d2[j],d[l+1]+1);
                            d3[j]=min(d3[j],d2[l+1]+1);
                        }
                        if(l<j-2)d3[j]=min(d3[j],d[l+2]+1);
                    }
                    c+=(d[j]==d2[j]&&d2[j]!=d3[j]);
                }
            }
            printf("%lld\n",c);
            continue;
        }
        if(id<=12){
            if(a[2]-a[1]>m/2)printf("0\n");
            else printf("%lld\n",max(0ll,n-m/(a[2]-a[1])*2+1));
            continue;
        }
    }
    return 0;
}
