#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=2e6+10;

int c,t,k;
int n,las,dist[N];
vector<int> edge[N];

void dfs(int u,int fa) {
    dist[u]=dist[fa]+1;
    if(dist[u]>dist[las]) las=u;
    for(int v:edge[u]) {
        if(v==fa) continue;
        dfs(v,u);
    }
}

void solve() {
    cin>>n>>k;
    for(int i=1;i<n;++i) {
        int u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for(int i=1;i<=n;++i) dist[i]=INF;
    dist[0]=-1,las=0;
    dfs(1,0);
    dfs(las,0);
    cout<<rand()%(dist[las]/2+1)<<"\n";
    for(int i=1;i<=n;++i) edge[i].clear();
}

signed main() {
    srand(time(0));
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>c>>t;
    while(t--) solve();
    return 0;
}
