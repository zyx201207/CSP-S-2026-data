#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,x[N],ans,n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);

        }
        if(c<=10){
            for(int i=1;i<=n;i++){
                for(int j=i+3;j<=n;j++){
                    if(x[i]+d>x[j]-d){
                        int l=lower_bound(x+1,x+n+1,x[j]-d)-x;
                        int r=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
                        if(l+1==r) ans++;
                    }
                }
            }
        printf("%lld\n",ans);
        }
        else{
            long long k=x[2]-x[1];
            for(long long i=1;i<=n-3;i++){
                long long dis=i*k;
                if(2*(d/k)*k==dis+k&&d*2>=dis){
                    ans+=n-i;
                }
            }
            printf("%lld\n",ans);
        }

    }
    return 0;
}

