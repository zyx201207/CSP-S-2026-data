#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+10;
LL n,m,a[N];
bool cmp(const LL &x,const LL &y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    if(m==1){
        LL maxn=-1;
        for(LL i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
        printf("%lld",maxn);
        return 0;
    }
    if(m==2){
        LL maxn=-1;
        for(LL i=1;i<=n;i++){
            for(LL j=i+1;j<=n;j++){
                maxn=max(maxn,LL(a[i]&a[j]));
            }
        }
        printf("%lld",maxn);
        return 0;
    }
    if(m==n){
        LL sum=LL(a[1]&a[2]);
        for(LL i=3;i<=n;i++){
            sum=LL(sum&a[i]);
        }
        printf("%lld",sum);
        return 0;
    }
    if(m==n-1){
        LL maxn=-1;
        for(LL i=1;i<=n;i++){
            LL sum=0;
            if(i==1){
                sum=a[2];
            }
            else{
                sum=a[1];
            }
            for(LL j=1;j<=n;j++){
                if(j!=i){
                    sum=LL(sum&a[j]);
                }
            }
            maxn=max(maxn,sum);
        }
        printf("%lld",maxn);
        return 0;
    }
    if(m==3){
        LL maxn=-1;
        for(LL i=1;i<=n;i++){
            for(LL j=i+1;j<=n;j++){
                for(LL k=j+1;k<=n;k++){
                    maxn=max(maxn,LL(LL(a[i]&a[j])&a[k]));
                }
            }
        }
        printf("%lld",maxn);
        return 0;
    }
    else{
        LL sum=0;
        sort(a+1,a+1+n,cmp);
        sum=a[1];
        for(LL i=2;i<=m;i++){
            sum=LL(sum&a[i]);
        }
        printf("%lld",sum);
    }
    return 0;
}

