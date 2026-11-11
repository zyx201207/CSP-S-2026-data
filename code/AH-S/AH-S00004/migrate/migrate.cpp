#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long  c,_;
    scanf("%lld %lld",&c,&_);
    while(_--){
        long long n,d;
        scanf("%lld %lld",&n,&d);
        for(long long i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        if(a[n]-a[1]<=d||n<=2){
            printf("0\n");
            continue;
        }
        long long s=a[2]=a[1];
        long long po=d/s;
        if(po!=2){
            printf("0\n");
        }else{
            long long ans=0;
            for(long long i=4;i<=n;i++){
                ans+=(i-2)/2;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
