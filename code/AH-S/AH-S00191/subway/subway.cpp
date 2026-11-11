#include<bits/stdc++.h>
using namespace std;
struct edge{
    int to,w;
};
int c,n,m,d,Q,w[500005],cnt;
vector<edge> g[10000005];
typedef pair<int,int> P;
priority_queue<P,vector<P>,greater<P>> q;
int vis[5000005],dis[5000005];
void dijkstra(int x){
    for(int i=1;i<=cnt;i++){
        vis[i]=0;
        dis[i]=0x3f3f3f3f;
    }
    dis[x]=0;
    q.push({0,x});
    while(!q.empty()){
        P h=q.top();
        q.pop();
        int u=h.second;
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=0;i<g[u].size();i++){
            edge tmp=g[u][i];
            if(dis[tmp.to]>dis[u]+tmp.w){
                dis[tmp.to]=dis[u]+tmp.w;
                q.push({dis[tmp.to],tmp.to});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    if(c==9||c==10||c==11){
        int a[1005][1005];
        memset(a,0x3f,sizeof(a));
        for(int i=1;i<=m;i++) a[i][i]=0;
        for(int i=1,k,u,x,v,y;i<=n;i++){
            cin>>k;
            if(k==1) continue;
            cin>>u>>x>>v>>y;
            a[u][v]=a[v][u]=x+y;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=m;k++){
                    if(a[i][k]+a[k][j]<a[i][j]) a[i][j]=a[i][k]+a[k][j];
                }
            }
        }
        while(Q--){
            int st,ed;
            cin>>st>>ed;
            cout<<a[st][ed]+w[st]+w[ed]<<endl;
        }
        return 0;
    }
    cnt=m+1;
    for(int i=1,k,u,t;i<=n;i++){
        cin>>k>>u>>t;
        g[u].push_back({cnt,t});
        g[cnt].push_back({u,t});
        cnt++;
        for(int j=2,v;j<=k;j++){
            scanf("%d%d",&v,&t);
            g[cnt-1].push_back({cnt,0});
            g[cnt].push_back({cnt-1,0});
            g[v].push_back({cnt,t});
            g[cnt].push_back({v,t});
            cnt++;
        }
    }
    while(Q--){
        int st,ed;
        cin>>st>>ed;
        dijkstra(st);
        cout<<dis[ed]+w[st]+w[ed]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
