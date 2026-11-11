#include <bits/stdc++.h>
typedef long long LL;

LL ru(){
    LL r=0,c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9'){
        r=r*10+c-'0';
        c=getchar();
    }
    return r;
}

namespace solve{
    LL c,n,m,d,q;
    const LL MAX_M=5e5+100,MAX_N=500+10,MAX_D=20+3,INF=0x3f3f3f3f3f3f3f;
    LL entry_s[MAX_M];
    std::pair<LL,LL> STATION[MAX_M][MAX_D];
    LL Pat[MAX_N][MAX_N];//path time(i->j)
    std::vector<std::pair<LL,LL> > K_IN[MAX_N];
    void STATION_push_back(LL i,std::pair<LL,LL> v){
        STATION[i][ ++STATION[i][0].first ] = v;
    }
    namespace dij{
        LL dist[MAX_N];
        void dij(int o){
            memset(dist,0x3f,sizeof(dist));
            std::priority_queue<std::pair<LL,LL> >  Q;
            Q.push({0,o}),dist[o]=0;
            while(!Q.empty()){
                auto p=Q.top();Q.pop();
                if(dist[p.second]<p.first)continue;
                for(int i=1;i<=n;i++){//obj:i
                    if(dist[p.second]+Pat[p.second][i]<dist[i]){
                        dist[i]=dist[p.second]+Pat[p.second][i];
                        Q.push({dist[i],i});
                    }
                }
            }
            for(int i=1;i<=n;i++)Pat[o][i]=dist[i];
        }
    }

    void solve(){
        memset(Pat,0x3f,sizeof(Pat));
        c=ru(),n=ru(),m=ru(),d=ru(),q=ru();
        for(int i=1;i<=m;i++)entry_s[i]=ru();
        for(int i=1;i<=n;i++){
            LL k=ru();
            for(int j=1;j<=k;j++){
                LL a=ru(),t=ru();
                K_IN[i].push_back({a,t});
                STATION_push_back(a,{i,t});
            }
        }
        ////
        for(int i=1;i<=n;i++){
            Pat[i][i]=0;
            for(auto v:K_IN[i]){
                for(int j=1;j<=STATION[v.first][0].first;j++){
                    Pat[i][ STATION[v.first][j].first ] = std::min(
                            Pat[i][ STATION[v.first][j].first ],
                            v.second + STATION[v.first][j].second);
                }
            }
        }
        for(int i=1;i<=n;i++){
                dij::dij(i);
        }
        //
        for(int i=1;i<=q;i++){
            LL x=ru(),y=ru(),ans=INF;
            for(int u=1;u<=STATION[x][0].first;u++){
                for(int v=1;v<=STATION[y][0].first;v++){
                    if(u==v)continue;
                    ans=std::min(ans,entry_s[x]+entry_s[y]+STATION[x][u].second+STATION[y][v].second+Pat[u][v]);
                }
            }
            printf("%lld\n",ans);
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    solve::solve();
    return 0;
}
