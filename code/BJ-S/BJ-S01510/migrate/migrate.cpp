#include<bits/stdc++.h>
using namespace std;
long long _;
long long t,n,d;
long long a[5000005];
long long head[5000005];
struct E{
    long long v,nxt;
}e[5000005];
long long cnt=1;
void ade(long long u,long long v){
    e[cnt].v=v;
    e[cnt].nxt=head[u];
    head[u]=cnt++;
}
priority_queue< pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > q;
long long dis[5000005],vis[5000005],c[5000005];
void dij(){
    while(q.size()){
        long long u=q.top().second;
        q.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        for(long long i=head[u];i;i=e[i].nxt){
            long long v=e[i].v;
            if(vis[v]){
                continue;
            }
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                q.push({dis[v],v});
            }
        }
    }
}
long long dfn[5000005];
void dfs(long long u,long long fa){
    dfn[u]=dfn[fa]+1;
    if(dfn[u]==dis[u]){
        c[u]++;
    }
    for(long long i=head[u];i;i=e[i].nxt){
        long long v=e[i].v;
        dfs(v,u);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&_,&t);
    while(t--){
        memset(e,0,sizeof(e));
        memset(head,0,sizeof(head));
        memset(a,0,sizeof(a));
        long long ans=0;
        scanf("%lld%lld",&n,&d);
        for(long long i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(long long i=1;i<=n;i++){
            for(long long j=i;j<=n;j++){
                if(a[j]-a[i]<=d&&i<j){
                    ade(i,j);
                }
            }
        }
        for(long long i=1;i<=n;i++){
            //memset(dis,0x3f3f3f3f,sizeof(dis));
            for(long long j=1;j<=n;j++){
                dis[j]=INT_MAX;
            }
            memset(vis,0,sizeof(vis));
            memset(dfn,0,sizeof(dfn));
            memset(c,0,sizeof(c));
            while(q.size()){
                q.pop();
            }
            q.push({0,i});
            dis[i]=0;
            dij();
            dfn[0]=-1;
            dfs(i,0);
            for(long long j=i;j<=n;j++){
                if(c[j]==2&&dis[j]!=1){
                    ans++;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
