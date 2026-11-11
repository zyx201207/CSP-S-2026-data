#include <bits/stdc++.h>
using namespace std;
vector<int> graph[510];
int timi[200010][510];
int w[200010];
int n,m;
int q;
bool vis[510];
int ans=INT_MAX;
void dfs(int u,int endd,int cnt,int edg){
    if(u==endd){
        ans=min(ans,cnt);
        return;
    }
    for(int i=1;i<=n;i++){
        if(timi[u][i]!=0){
            int nx=graph[i][u+1];
            vis[nx]=true;
            dfs(nx,endd,cnt+(i==edg?0:(timi[u][edg]+timi[u][i])),i);
            nx=graph[i][u-1];
            vis[nx]=true;
            dfs(nx,endd,cnt+(i==edg?0:(timi[u][edg]+timi[u][i])),i);
        }
    }

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;cin>>c;
    int d;
    cin>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;++j){
            int a,t;
            cin>>a>>t;
            graph[i].push_back(a);

            timi[a][i]=t;
        }
    }
    while(q--){

        int sx,fx;

        // cin>>sx>>fx;

        ans=INT_MAX;

        memset(vis,false,sizeof(vis));

        for(int i=1;i<=n;i++){

            if(timi[sx][i]!=0){
                vis[sx]=true;
                dfs(sx,fx,w[sx]+w[fx]+timi[sx][i],i);
            }
        }
        cout<<ans<<endl;

    }
}
