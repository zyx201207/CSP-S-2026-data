#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,p[500520],dis[500520],vis[500520],tim=0;
struct nd {
    int v,w;
    bool operator <(const nd b) const{
        return w>b.w;
    }
};
vector<nd> G[500520];
void dij(int s,int t){
    priority_queue<nd> q;
    tim++;
    dis[s]=0;
    vis[s]=tim;
    nd tmp;
    tmp.v=s;
    tmp.w=0;
    q.push(tmp);
    while(!q.empty()){
        nd now=q.top();q.pop();
        int u=now.v;
        if (u==t) return ;
        for (nd r : G[u]){
            if(vis[r.v]==tim) continue;
            vis[r.v]=tim;
            dis[r.v]=dis[u]+r.w;
            nd tmp;
            tmp.v=r.v;
            tmp.w=dis[r.v];
            q.push(tmp);
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++) cin>>p[i];
    for (int i=1;i<=n;i++) {
        int k;
        cin>>k;
        for (int j=1;j<=k;j++) {
            int u,t;
            cin>>u>>t;
            nd tmp;
            tmp.v=u;
            tmp.w=t;
            G[i+m].push_back(tmp);
            tmp.v=i+m;
            G[u].push_back(tmp);
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        dij(u,v);
        cout<<dis[v]+p[u]+p[v]<<"\n";
    }
    return 0;
}
//you shui neng jiao jiao wo er fen tu zui duan lu de you hua fang fa???