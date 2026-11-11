#include <bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long a[2000005];
long long d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d %d",&c,&t);
    while(t){
        scanf("%d %lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        long long p=a[2]-a[1];
        //printf("%lld\n",p);
        if(d<2*p){
            printf("0");
            //printf("wwrroonngg");
            continue;
        }
        long long ans=0;
        for(int v=1;v<=n;v++){
            for(int u=1;u<v;u++){
                //printf("%lld\n",a[u]-a[v]);
                if(a[v]-a[u]>=2*p){
                    ans++;
                }
            }
        }
        printf("%lld",ans);
        t--;
    }
    return 0;
}
