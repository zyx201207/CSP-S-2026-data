#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

struct Edge {
    int to;
    ll w;
    Edge(int t, ll ww): to(t), w(ww){}
};

vector<vector<Edge>> g;
vector<ll> w;

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;

    w.resize(m+1);
    for(int i=1;i<=m;i++) {
        cin>>w[i];
    }

    int total_node=m+n;
    g.resize(total_node+1);

    for(int i=1;i<=n;i++) {
        int k;
        cin>>k;
        int line_id=m+i;
        for(int j=1;j<=k;j++) {
            int u; ll t;
            cin >> u >> t;
            g[u].emplace_back(line_id,t);
            g[line_id].emplace_back(u,t);
        }
    }
    while(q--) {
        int x,y;
        cin>>x>>y;
        if(x==y) {
            cout<<w[x]+w[y]<<'\n';
            continue;
        }
        vector<ll> dis(total_node+1,INF);
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> pq;
        dis[x]=0;
        pq.emplace(0,x);
        while(!pq.empty()) {
            auto [dnow,u]=pq.top();
            pq.pop();
            if(dnow>dis[u]) continue;
            for(auto &e : g[u]) {
                int v=e.to;
                ll nw=dnow + e.w;
                if(nw<dis[v]){
                    dis[v]=nw;
                    pq.emplace(nw,v);
                }
            }
        }
        ll ans=w[x]+dis[y]+w[y];
        cout<<ans<<'\n';
    }
    return 0;
}
