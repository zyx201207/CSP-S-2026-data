#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500010];
long long wt;
bool h[510][500010];
int k[500010];
vector<long long> g[500010];
bool vis[500010];
struct node{
    int weizhi;
    long long lu;
};
void topo(int x,int y){
    long long t=w[x]+w[y];
    memset(vis,0,sizeof(vis));
    queue<node> q;
    q.push({x,w[x]+w[y]});
    while(!q.empty()){
        node cur=q.front();
        if(cur.weizhi==y) break;
        q.pop();
        vis[cur.weizhi]=1;
        for(auto v:g[cur.weizhi]){
            if(!vis[v]) q.push({v,cur.lu+wt*2});
        }
    }
    cout<<q.front().lu<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        int u,tu,v,tv;
        cin>>u>>tu>>v>>tv;
        g[u].push_back(v);
        g[v].push_back(u);
        wt=tu;
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        topo(x,y);
    }
    return 0;
}
