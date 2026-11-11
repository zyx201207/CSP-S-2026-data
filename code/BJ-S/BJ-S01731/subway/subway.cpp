#include<bits/stdc++.h>
using namespace std;
#define int long long
const int K=5e5+5;
const int N=505;
int c,n,m,d,q;
int w[K];
vector<pair<int,int> > s[K];
vector<pair<int,int> > p[N];
bool vis[N];
int dis[N][N];
void dijsktra(int st){
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    memset(vis,0,sizeof(vis));
    q.push({0,st});
    dis[st][st]=0;
    while(!q.empty()){
        auto now=q.top();
        q.pop();
        //cout<<now.second<<"kk\n";
        if(vis[now.second]) continue;
        vis[now.second]=1;
        //cout<<now.second<<"tt\n";
        for(auto to:p[now.second]){
            if(dis[st][to.first]>now.first+to.second){
                dis[st][to.first]=now.first+to.second;
                q.push({dis[st][to.first],to.first});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    int k,a,t;
    for(int i=1;i<=n;++i){
        cin>>k;
        for(int j=1;j<=k;++j){
            cin>>a>>t;
            for(auto to:s[a]){
                p[to.first].emplace_back(i,to.second+t);
                p[i].emplace_back(to.first,to.second+t);
            }
            s[a].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;++i) dijsktra(i);
    int u,v;
    int ans=1e18;
    while(q--){
        ans=1e18;
        cin>>u>>v;
        for(auto st:s[u]){
            for(auto ed:s[v]){
                ans=min(ans,st.second+ed.second+dis[st.first][ed.first]);
            }
        }
        cout<<ans+w[u]+w[v]<<"\n";
    }
    return 0;
}