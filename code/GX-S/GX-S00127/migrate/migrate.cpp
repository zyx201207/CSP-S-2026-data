#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[114514],ans,mi=99999999,itsrealme=0;
inline void FunctionMigrate(long long u,long long v,long long a,long long tick){
    if((tick==mi && a!=v) || (tick>mi)) return;
    if(a==v){
        if(tick<mi){
            mi=tick;
            ans=1;
        }else ans++;
        return;
    }
    for(long long f=v;f>a;f--){
        if(x[f]-x[a]<=d){
            FunctionMigrate(u,v,f,tick+1);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    for(long long i=1;i<=t;i++){
        scanf("%lld%lld",&n,&d);
        for(long long j=1;j<=n;j++) scanf("%lld",&x[j]);
        itsrealme=0;
        for(long long j=1;j<=n;j++){
            for(long long k=j+1;k<=n;k++){
                ans=0;
                mi=99999999;
                FunctionMigrate(j,k,j,0);
                if(ans==2) itsrealme++;
            }
        }
        printf("%lld\n",itsrealme);
    }
}
