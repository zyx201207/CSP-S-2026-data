#include<bits/stdc++.h>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
long long c,t,n,d,p,ans,f[310][310],g[310][310],x[2000010];
long long read(){
    long long x=0,p=1;char ac=getchar();
    while(ac!='-' && (ac<'0' || ac>'9')) ac=getchar();
    if(ac=='-') p=-1,ac=getchar();
    while(ac>='0' && ac<='9') x=x*10+ac-'0',ac=getchar();
    return x*p;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),t=read();
    while(t--){
        n=read(),d=read();
        for(long long i=1;i<=n;i++)
            x[i]=read();
        if(c==11 || c==12){
            p=x[2]-x[1];
            if(p>=d) printf("0\n");
            else printf("%lld\n",max(0ll,n-2ll*(d/p)+1));
        }
        if(c>=1 && c<=6){
            ans=0;
            for(long long i=1;i<=n;i++)
                for(long long j=1;j<=n;j++)
                    f[i][j]=inf,g[i][j]=1;
            for(long long i=1;i<=n;i++)
                for(long long j=i+1;j<=n;j++)
                    if(x[j]-x[i]<=d) f[i][j]=f[j][i]=1;
            // printf("pre test delta : \n");
            // for(long long i=1;i<=n;i++){
            //     for(long long j=1;j<=n;j++)
            //         printf("%lld ",x[j]-x[i]);
            //     printf("\n");
            // }
            // printf("pre test f :\n");
            // for(long long i=1;i<=n;i++){
            //     for(long long j=1;j<=n;j++)
            //         printf("%lld ",f[i][j]);
            //     printf("\n");
            // }
            for(long long k=1;k<=n;k++)
                for(long long i=1;i<=n;i++)
                    for(long long j=1;j<=n;j++)
                        if(f[i][k]!=inf && f[k][j]!=inf)
                            if(f[i][j]>f[i][k]+f[k][j])
                                f[i][j]=f[i][k]+f[k][j],g[i][j]=g[i][k]*g[k][j];
                            else if(f[i][j]==f[i][k]+f[k][j]) g[i][j]+=(g[i][k]*g[k][j]);
            // printf("f : \n");
            // for(long long i=1;i<=n;i++){
            //     for(long long j=1;j<=n;j++)
            //         printf("%lld ",f[i][j]);
            //     printf("\n");
            // }
            // printf("g : \n");
            // for(long long i=1;i<=n;i++){
            //     for(long long j=1;j<=n;j++)
            //         printf("%lld ",g[i][j]);
            //     printf("\n");
            // }
            for(long long i=1;i<=n;i++)
                for(long long j=i+1;j<=n;j++)
                    if(g[i][j]==2) ans++;
            printf("%lld\n",ans);
        }
    }
    return 0;
}