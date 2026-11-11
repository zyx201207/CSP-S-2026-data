#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int c,n,m,d,q,w[N],clk;
vector<vector<pair<int,int>>> adj;

void solve(){
    int st,en;
    cin>>st>>en;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dis(m*(d+1)+10,0x3f3f3f3f);
    pq.push({0,st});
    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();
        if(u.second == en){
            cout<<u.first+w[st]+w[en]<<'\n';
            return ;
        }
        if(u.first >= dis[u.second]) continue;
        dis[u.second] = u.first;
        for(auto i : adj[u.second]){
            pq.push({u.first+i.second,i.first});
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>c>>n>>m>>d>>q;
    if(7<=c && c<=11){
        adj.resize(m+10);
        for(int i = 1;i<=m;i++) cin>>w[i];
        for(int i = 1;i<=n;i++){
            int k,a1,t1,a2,t2;
            cin>>k>>a1>>t1>>a2>>t2;
            adj[a1].push_back({a2,t1+t2});
            adj[a2].push_back({a1,t1+t2});
        }
        while(q--) solve();
        return 0;
    }
    adj.resize(m*(d+1)+10);
    clk = m+1;
    for(int i = 1;i<=m;i++) cin>>w[i];
    for(int i = 1;i<=n;i++){
        int k;
        cin>>k;
        vector<int> last_sta;
        for(int j = 1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            adj[a].push_back({clk,t});
            adj[clk].push_back({a,t});
            for(int k : last_sta){
                adj[k].push_back({clk,0});
                adj[clk].push_back({k,0});
            }
            last_sta.push_back(clk);
            clk++;
        }
    }
    while(q--) solve();

    return 0;
}
