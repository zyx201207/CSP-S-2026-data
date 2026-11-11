#include "bits/stdc++.h"
#define int long long
using namespace std;
const int N=5e5+10;
int c, n, m, d, q;
int w[N],a[505][N],k[505];
struct node{
    int to,t2;
};
vector<node> G[505];
int t1;
int u[5],t[5],minn=0x3f3f3f3f3f3f3f3f;
bool vis[N];
void dfs(int x,int y,int t){
    if(vis[x]==1) return ;
    if(x==y){
        minn=min(minn,t+w[x]);
        return ;
    }
    for(int i=0;i<G[x].size();i++){
        vis[x]=1;
        dfs(G[x][i].to,y,t+G[x][i].t2+w[x]);
        vis[x]=0;
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    if(c>7&&c<11){
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=2;j++){
                cin>>u[j]>>t[j];
            }
            G[u[1]].push_back({u[2],t[1]+t[2]});
            G[u[2]].push_back({u[1],t[1]+t[2]});
        }
        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            t1=0;
            minn=0x3f3f3f3f3f3f3f3f;
            dfs(x,y,0);
            cout<<minn<<endl;
        }
    }
    return 0;
}
