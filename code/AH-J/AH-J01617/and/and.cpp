#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[200010],maxn,sum,maxn2;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(i==1){
            sum=a[1];
        }
        else{
            sum=sum&a[i];
        }
        maxn=max(maxn,a[i]);
    }
    if(m==1){
        printf("%lld",maxn);
    }
    if(m==2){
        for(LL i=1;i<=n;i++){
            for(LL j=i+1;j<=n;j++){
                maxn2=max(maxn2,a[i]&a[j]);
            }
        }
        printf("%lld",maxn2);
    }
    if(m==n){
        printf("%lld",sum);
    }
    return 0;
}
