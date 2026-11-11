#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
const int maxm = 4e6 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,cnt,head[maxn],s,t;
ll tim_zt[maxn],dist[maxn];
bool vis[maxn];
struct Edge{
    int to;
    int next;
    ll w;
}edge[maxm*2+1];
struct Edge2{
    int bh;
    ll w;
    bool operator<(const Edge2 & zyy)const{
        return zyy.w<w;
    }
};
void add(int u,int v,ll w){
    cnt++;
    edge[cnt].w=w;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
void Dijkstra(){
    memset(vis,false,sizeof(vis));
    memset(dist,INF,sizeof(dist));
    priority_queue<Edge2> q;
    dist[s]=0;
    q.push({s,dist[s]});
    while(!q.empty()){
        Edge2 zyy=q.top();
        q.pop();
        int u=zyy.bh;
        if(vis[u]){
            continue;
        }
        vis[u]=true;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            ll w=edge[i].w;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                q.push({v,dist[v]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>tim_zt[i];
        add(i,i+m,tim_zt[i]);
        add(i+m,i,tim_zt[i]);
    }
    int temp_bh=2*m;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        temp_bh++;
        for(int j=1;j<=k;j++){
            int bh;
            ll t;
            cin>>bh>>t;
            add(temp_bh,bh+m,t);
            add(bh+m,temp_bh,t);
        }
    }
    while(q--){
        cin>>s>>t;
        Dijkstra();
        cout<<dist[t]<<endl;
    }
    return 0;
}