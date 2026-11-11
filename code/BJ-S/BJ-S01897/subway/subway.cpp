#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[600000],dis[700][700];
bool vis[700][700];
vector<pair<int,int> > thr[600000];
struct node{
    int t,w;
};
vector<node> edge[600];
void dij(int st){
    priority_queue<pair<int,int> > q;
    dis[st][st]=0;
    q.push({0,st});
    while(!q.empty()){
        int x=q.top().second;
        q.pop();
        if(vis[st][x]) continue;
        vis[st][x]=0;
        for(auto it:edge[x]){
            if(dis[st][it.t]>dis[st][x]+it.w){
                dis[st][it.t]=dis[st][x]+it.w;
                q.push({dis[st][it.t],it.t});
            }
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
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            thr[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(auto it:thr[i]){
            for(auto it2:thr[i]){
                if(it.first==it2.first) continue;
                edge[it.first].push_back({it2.first,it.second+it2.second});
            }
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        dij(i);
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        int base=w[u]+w[v],res=1e18;
        for(auto it:thr[u]){
            for(auto it2:thr[v]){
                res=min(res,it.second+it2.second+dis[it.first][it2.first]);
            }
        }
        cout<<res+base<<endl;
    }
    return 0;
}

