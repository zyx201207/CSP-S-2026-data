#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q1,k[505],u,v;
int w[305],a[505][305],t[505][305];
int dis[305][505],vis[305][505];
struct node{
    int id,dis,x;
};
bool operator < (node a,node b){
    return a.dis>b.dis;
}
vector<node>g[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q1);
    for(int i=1;i<=m;i++)scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%d%d",&a[i][j],&t[i][j]);
            for(int _k=1;_k<j;_k++)g[a[i][_k]].push_back({a[i][j],t[i][j],i});
        }
    }
    priority_queue<node>q;
    while(q1--){
        while(!q.empty())q.pop();
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&u,&v);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==u){
                    q.push({u,t[i][j],i});
                    dis[u][i]=t[i][j];
                }
            }
        }
        while(!q.empty()){
            int now=q.top().id,ti=q.top().x;
            q.pop();
            if(vis[now][ti])continue;
            vis[now][ti]=1;
            for(int i=0;i<g[u].size();i++){
                int nx=g[u][i].id,ti2=g[u][i].x;
                if(ti!=ti2){
                    int _x;
                    for(int j=1;j<=k[ti2];j++)
                        if(a[ti2][j]==nx){
                            _x=j;
                            break;
                        }
                    if(dis[nx][ti2]>dis[now][ti]+g[u][i].dis+t[ti2][_x]){
                        dis[nx][ti2]=dis[now][ti]+g[u][i].dis+t[ti2][_x];
                        q.push({nx,dis[nx][ti2],ti2});
                    }
                }else{
                    if(dis[nx][ti]>dis[now][ti]+g[u][i].dis){
                        dis[nx][ti]=dis[now][ti]+g[u][i].dis;
                        q.push({nx,dis[nx][ti],ti});
                    }
                }
            }
        }
        printf("%d\n",w[u]+w[v]);
    }
    return 0;
}
