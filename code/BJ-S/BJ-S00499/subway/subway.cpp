#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,Q,W[N];
bool vis[N];
struct Node{
    int v,w,lw;
};
vector<Node> g[N];
queue<Node> q;
void bfs(int s,int t){
    while(!q.empty())   q.pop();
    memset(vis,0,sizeof(vis));
    q.push({s,0});
    while(!q.empty()){
        auto x=q.front();
        int u=x.v,dis=x.w;
        q.pop();
        for(auto y:g[u]){
            int v=y.v,w=y.w,lw=y.lw;
            if(!vis[v]){
                vis[v]=true;
                q.push({v,dis+w+lw});
                if(v==t){
                    cout<<W[s]+W[t]+dis+w+lw<<'\n';
                    return;
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>Q;
    for(int i=1;i<=n;i++)
        cin>>W[i];
    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        for(int j=1,lw;j<=k;j++){
            int v,w;
            cin>>v>>w;
            g[i].push_back({v,w,lw});
            g[v].push_back({i,w,lw});
            lw=w;
        }
    }
    while(Q--){
        int s,t;
        cin>>s>>t;
        bfs(s,t);
    }
    return 0;
}