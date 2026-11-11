#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<pair<int,int>>> adj;

signed main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    vector<int> w(m+1);
    adj.resize(m+1);
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		adj.push_back(vector<pair<int,int>>(0));
		int u=(int)adj.size()-1;
		for(int _=1;_<=k;_++){
			int v,t;
			cin >> v >> t;
			adj.push_back(vector<pair<int,int>>(0));
			adj[(int)adj.size()-1].emplace_back(v,t);
			adj[v].emplace_back((int)adj.size()-1,t);
			adj[(int)adj.size()-1].emplace_back(u,0);
			adj[u].emplace_back((int)adj.size()-1,0);
		}
    }
    map<pair<int,int>,int> ans_store;
    while(q--){
		int u,v,cost=0;
		cin >> u >> v;
		if(ans_store[make_pair(u,v)]){
			cout << ans_store[make_pair(u,v)] << endl;
			continue;
		}
		cost+=w[u]+w[v];
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> bfs;
		bfs.push(make_pair(cost,u));
		vector<bool> vis(adj.size(),false);
		while(!bfs.empty()){
			pair<int,int> cur=bfs.top();
			bfs.pop();
			if(vis[cur.second]) continue;
			vis[cur.second]=true;
			if(cur.second<=m){
				ans_store[make_pair(u,cur.second)]=ans_store[make_pair(cur.second,u)]=cur.first-w[v]+w[cur.second];
			}
			if(cur.second==v){
				cout << cur.first << endl;
				break;
			}
			for(int i=0;i<adj[cur.second].size();i++){
				bfs.push(make_pair(adj[cur.second][i].second+cur.first,adj[cur.second][i].first));
			}
		}
	}
    return 0;
}
