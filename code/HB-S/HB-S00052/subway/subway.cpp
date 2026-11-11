#include<bits/stdc++.h>
using namespace std;
using int64=long long;
vector<int64> g[505];
int64 w[500005],f[505][505],dist[505];
bool vis[500005][505];
int c,n,m,d,q,k;
void bfs(){
    queue<int> q;
    dist[1]=0;
    q.push(1);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:g[u]){
            if(dist[v]) continue;
            dist[v]=dist[u]+1;
            q.push(v);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64 x,y,t;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>x>>y;
            t=y;
            vis[x][i]=1;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(!vis[i][j]) continue;
            for(int l=j+1;l<=n;l++){
                if(!vis[i][l]) continue;
                g[j].push_back(l);
                g[l].push_back(j);
            }
        }
    }
    bfs();
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<abs(dist[v]-dist[u]+1)*t*2+w[u]+w[v]<<'\n';
    }
    return 0;
}
