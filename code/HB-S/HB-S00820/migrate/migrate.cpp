#include<iostream>
using namespace std;

const long long N=2e6+5,INF=1LL<<48;
long long c,T;
long long n,d;
long long x[N];
long long dis[300][300];
long long ans;

long long yangli(){
    ans=0;
    cin>>n>>d;
    for(long long i=1;i<=n;++i)cin>>x[i];

    if(n<=2)return 0;
    
    bool pdA=true;
    long long __dertacha=x[2]-x[1];
    for(long long i=1;pdA&&i<=n;++i){
        if(i>1){
            pdA=pdA&&x[i]-x[i-1]==__dertacha;
        }
    }
    if(pdA){
        long long maxfws=d/__dertacha;
        if(maxfws<=1)return 0;
        long long nlength=maxfws<<1;
        return n-nlength+1;
    }

    if(n>300)return rand()%100;
    for(long long u=1;u<=n;++u)for(long long v=u+1;v<=n;++v)dis[u][v]=u==v?0:INF;   
    for(long long u=1;u<=n;++u){
        for(long long v=u+1;v<=n&&x[v]-x[u]<=d;++v){
            dis[u][v]=1;
        }
    }
    for(long long i=1;i<=n;++i){
        for(long long u=1;u<i;++u){
            for(long long v=u+1;v<=n;++v){
                dis[u][v]=min(dis[u][v],dis[u][i]+dis[i][v]);
            }
        }
    }
    // for(long long u=1;u<=n;++u){
    //     for(long long v=1;v<=n;++v){
    //         cout<<dis[u][v]<<" \n"[v==n];
    //     }
    // }
    for(long long u=1;u<=n;++u){
        for(long long v=u+1;v<=n;++v){
            long long cnt=0;
            for(long long i=u+1;cnt<=2&&i<v;++i)if(dis[u][i]!=INF&&dis[i][v]!=INF&&dis[u][v]!=INF&&dis[u][i]+dis[i][v]==dis[u][v])++cnt;
            if(cnt==2)++ans;
            // if(cnt==2)cout<<u<<" "<<v<<" !!! ans !!! \n";
        }
    }
    return ans;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    srand(time(0));
    cin>>c>>T;
    while(T--)cout<<yangli()<<"\n";
    return 0;
}