#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500001];
int cnt=0;
struct no{
    int a,t;
}b[500001];
int g[1001][1001];
int k[1001];
int dis[1001];
int c,n,m,d,Q;
int sum[1001];
void dijkstra(int x,int y){
    memset(dis,0x3f,sizeof(dis));
    priority_queue<pair<int,int> >q;
    dis[x]=0;
    q.push({0,x});
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(u==y)return;
        for(int i=1;i<=n;i++){
            if(g[u][i]<0x3f3f3f3f){
                if(dis[i]>dis[u]+g[u][i]){
                    dis[i]=dis[u]+g[u][i];
                    q.push({-dis[i],i});
                }
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(g,0x3f,sizeof(g));
    cin>>c>>m>>n>>d>>Q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>k[i];
        sum[i]=sum[i-1]+k[i];
        for(int j=1;j<=k[i];j++){
                cnt++;
            cin>>b[cnt].a>>b[cnt].t;
        }
    }
    if(cnt<=400){
        for(int l=1;l<=m;l++){
            for(int i=sum[l-1]+1;i<=sum[l];i++){
            for(int j=i+1;j<=sum[l];j++){
                g[b[i].a][b[j].a]=min(g[b[i].a][b[j].a],b[i].t+b[j].t);
                g[b[j].a][b[i].a]=min(g[b[j].a][b[i].a],b[i].t+b[j].t);
            }
        }
        }
        while(Q--){
            int u,v;
            cin>>u>>v;
            dijkstra(u,v);
            cout<<dis[v]+a[u]+a[v]<<"\n";
        }
    }
    else if(cnt<=1000){
        for(int l=1;l<=m;l++){
                int i=sum[l]-1,j=sum[l];
                g[b[i].a][b[j].a]=min(g[b[i].a][b[j].a],b[i].t+b[j].t);
                g[b[j].a][b[i].a]=min(g[b[j].a][b[i].a],b[i].t+b[j].t);
        }
        while(Q--){
            int u,v;
            cin>>u>>v;
            dijkstra(u,v);
            cout<<dis[v]+a[u]+a[v]<<"\n";
        }
    }
}
