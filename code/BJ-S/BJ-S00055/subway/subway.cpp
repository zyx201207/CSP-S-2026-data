#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5+10;
int c,n,m,D,Q,W[N],d[N],vis[N];
struct node{
    int v,w;
    bool operator<(const node A)const{
        return w>A.w;
    }
};
priority_queue <node> q;
vector<node> g[N];
void dijkstra(int S,int T){
    while(!q.empty()) q.pop();
    memset(d,0x3f,sizeof d);
    memset(vis,0,sizeof vis);
    d[S]=0;
    q.push({S,0});
    while(!q.empty()){
        int u=q.top().v;

        q.pop();
        if(vis[u]) continue;

        vis[u]=1;
        if(u==T) break;
        for(auto nd:g[u]){
            int v=nd.v,w=nd.w;
            if(vis[v]) continue;
            if(g[v].size()==1&&v!=T)continue;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                q.push({v,d[v]});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>c>>n>>m>>D>>Q;
    for(int i=1;i<=m;++i){
        cin>>W[i];
    }

    int id=m+1;
    for(int i=1;i<=n;++i){
        int k; cin>>k;
        for(int i=1;i<=k;++i){
            int ai,ki;cin>>ai>>ki;
            g[id].push_back({ai,ki});
            g[ai].push_back({id,ki});
        }
        id++;

    }
    for(int i=1;i<=Q;++i){
        int x,y;
        cin>>x>>y;
        dijkstra(x,y);
        cout<<d[y]+W[x]+W[y]<<endl;
    }

    return 0;

}
