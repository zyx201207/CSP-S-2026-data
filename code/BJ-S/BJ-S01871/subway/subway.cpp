#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int N=5e2+5,M=5e5+5;
struct node{
    int u,w;
    vector<int> l1;
    bool operator<(const node &a)const{
        return a.w<w;
    }
};
priority_queue<node> pq;
vector<int> g[M],l[M];
int c,n,m,d,q,w[M],a[N][M],t[N][M],x,y,k[N];
bool vis[M];
long long dist[M];
void dijkstra(int st){
    for(int i=1;i<=m;i++) vis[i]=0,dist[i]=0x3f3f3f3f;
    dist[st]=0;
    while(!pq.empty()) pq.pop();
    vector<int> b;
    for(int i:l[st]) b.push_back(i);
    pq.push({st,0,b});
    while(!pq.empty()){
        int u=pq.top().u,w=pq.top().w;
        vector<int> l2=pq.top().l1;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(unsigned int i=0;i<g[u].size();i++){
            int v=g[u][i];
            bool f=0;
            for(int j:l2){
                for(int k:l[v]){
                    if(j==k){
                        f=1;
                        break;
                    }
                }
            }
            if(f){
                if(dist[v]>dist[u]){
                    dist[v]=dist[u];
                    pq.push({v,dist[v],l[v]});
                }
            }
            for(int j:l[v]){
                pq.push({v,dist[u]+t[u][v]+t[v][u],l[v]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%d%d",&a[i][j],&t[i][a[i][j]]);
            l[a[i][j]].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            if(j!=1){
                g[a[i][j]].push_back(a[i][j-1]);
                g[a[i][j-1]].push_back(a[i][j]);
            }
        }
    }
    //floyd();
    for(int i=1;i<=q;i++){
        scanf("%d%d",&x,&y);
        dijkstra(x);
        printf("%lld\n",w[x]+w[y]+dist[y]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
