#include<bits/stdc++.h>

using namespace std;

int c, t, n, k;
vector<vector<int>> g;

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		g.resize(n + 5);
		for(int i = 0;i < n;i++){
			int u, v; cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
}
