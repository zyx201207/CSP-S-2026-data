#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N=10005,INF=1e9+5;

int c,n,m,d,q,ans;
int w[N],k[N],a[N][N],t[N][N],x[N],y[N],vis[N];
vector<pii> g[N];

void dfs(int u,int v,int cnt){
    if (u==v) ans=min(ans,cnt);
    for (int i=0;i<g[u].size();i++){
        pii o=g[u][i];
        if (o.first==u || vis[g[u][i].first]==1) continue;
        vis[g[u][i].first]=1;
        dfs(o.first,v,cnt+o.second);
        vis[g[u][i].first]=0;
    }
    return;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++) cin >> w[i];
    for (int i=1;i<=n;i++){
        cin >> k[i];
        for (int j=1;j<=k[i];j++){
                int V,W;
            cin >> V >> W;
            g[i+m].push_back({V,W});
            g[V].push_back({i+m,W});
        }
    }
    for (int i=1;i<=q;i++){
        cin >> x[i] >> y[i];
        ans=INT_MAX;
        dfs(x[i],y[i],0);
        cout << ans+w[x[i]]+w[y[i]] << "\n";
    }
}
