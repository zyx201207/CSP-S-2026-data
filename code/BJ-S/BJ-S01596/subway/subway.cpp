#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=5e2+5;
int c,n,m,d,q,w[M],k[N],a[M][N],t[M][N],x,y,ans=1e9;
bool vis[M];
struct node{
    int v,w;
};
vector<node> g[M];
void dfs(int now,int sum){
    if(now==y){
        ans=min(ans,sum);
        return;
    }
    for(auto e:g[now]){
        if(vis[e.v])  continue;
        vis[e.v]=1;
        dfs(e.v,sum+e.w);
        vis[e.v]=0;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
        for(int j=1;j<=k[i];j++){
            for(int l=1;l<=k[i];l++){
                g[a[i][j]].push_back({a[i][l],t[i][j]+t[i][l]});
                g[a[i][l]].push_back({a[i][j],t[i][j]+t[i][l]});
            }
        }
    }
    while(q--){
        ans=1e9;
        cin>>x>>y;
        memset(vis,0,sizeof(vis));
        vis[x]=1;
        dfs(x,w[x]+w[y]);
        cout<<ans<<"\n";
    }
    return 0;
}
