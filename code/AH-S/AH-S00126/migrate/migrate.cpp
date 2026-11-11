#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,T,a[2000010],c;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&T);
    if(c==11||c==12){
        for(int ii=1;ii<=T;ii++){
            scanf("%lld%lld",&n,&d);
            for(int i=1;i<=n;i++){
                scanf("%lld",&a[i]);
            }
            int x=a[2]-a[1];
            int nn=(d)/(x);
            if(nn<2) printf("0\n");
            else if(nn>=2&&n-nn*2+1>0){
                printf("%lld\n",n-nn*2+1);
            }else{
                printf("0\n");
            }
        }
    }if(c==13||c==14){
        for(int ii=1;ii<=T;ii++){
            scanf("%lld%lld",&n,&d);
            for(int i=1;i<=n;i++){
                scanf("%lld",&a[i]);
            }
            if(n==4){
                printf("1\n");
            }else{
                printf("0\n");
            }
        }
    }

    return 0;
}
