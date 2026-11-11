#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],dis[1005][1005],dt[505][505],ds[505][505];
vector<long long>a[505],t[505],fx[500005],tmm[500005];
struct sss{
    long long id,tm;
    bool operator<(const sss x)const{
        return x.tm<tm;
    }
};
priority_queue<sss>que;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(long long i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        a[i].push_back(0);
        t[i].push_back(0);
        for(int j=1;j<=k[i];j++){
            long long _;
            scanf("%lld",&_);
            a[i].push_back(_);
            fx[_].push_back(i);
            long long __=_;
            scanf("%lld",&_);
            t[i].push_back(_);
            tmm[__].push_back(_);
        }
    }
    if(c<=11){
        for(int _=1;_<=m;_++){
            for(int j=1;j<=m;j++)dis[_][j]=0x3f3f3f3f3f3f3f3f;
            dis[_][_]=w[_];
            while(!que.empty())que.pop();
            que.push((sss){_,w[_]});
            while(!que.empty()){
                sss now=que.top();
                que.pop();
                if(dis[_][now.id]<now.tm)continue;
                for(int i=0;i<fx[now.id].size();i++){
                    long long nam=fx[now.id][i];
                    long long flag=0;
                    for(int j=1;j<=k[nam];j++){
                        if(a[nam][j]==now.id)flag=j;
                    }
                    for(int j=1;j<=k[nam];j++){
                        if(dis[_][now.id]+t[nam][j]+t[nam][flag]<dis[_][a[nam][j]]){
                            dis[_][a[nam][j]]=dis[_][now.id]+t[nam][j]+t[nam][flag];
                            que.push((sss){a[nam][j],dis[_][a[nam][j]]});
                        }
                    }
                }
            }
        }
        for(int i=1;i<=q;i++){
            long long x,y;
            scanf("%lld%lld",&x,&y);
            printf("%lld\n",dis[x][y]+w[y]);
        }
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)ds[i][j]=0x3f3f3f3f3f3f3f3f;
            ds[i][i]=0;
            for(int j=1;j<=k[i];j++){
                for(int z=0;z<fx[a[i][j]].size();z++){
                    long long bl=fx[a[i][j]][z];
                    ds[i][bl]=min(ds[i][bl],t[i][j]+tmm[a[i][j]][z]);
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)dt[i][j]=0x3f3f3f3f3f3f3f3f;
            dt[i][i]=0;
            while(!que.empty())que.pop();
            que.push((sss){i,0});
            while(!que.empty()){
                sss now=que.top();
                que.pop();
                if(dt[i][now.id]<now.tm)continue;
                for(int j=1;j<=n;j++){
                    if(dt[i][j]>dt[i][now.id]+ds[now.id][j]){
                        dt[i][j]=dt[i][now.id]+ds[now.id][j];
                        que.push((sss){j,dt[i][j]});
                    }
                }
            }
        }
        while(q--){
            long long x,y;
            scanf("%lld%lld",&x,&y);
            long long ans=0x3f3f3f3f3f3f3f3f;
            for(int i=0;i<fx[x].size();i++){
                for(int j=0;j<fx[y].size();j++){
                    ans=min(ans,w[x]+w[y]+dt[fx[x][i]][fx[y][j]]+tmm[x][i]+tmm[y][j]);
                }
            }
            printf("%lld\n",ans);
        }
        
    }
    return 0;
}