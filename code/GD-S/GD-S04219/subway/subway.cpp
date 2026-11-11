#include<bits/stdc++.h>

using namespace std;

int c, n, m, d, q;
vector<vector<pair<int ,int>>> g;

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	g.resize(2 * n + 1 + d);
	for(int i = 0;i < m;i++){
		int w; cin>>w;
		g[i].push_back({n + i, w});
		g[n + i].push_back({i, w});
	}
	for(int j = 0;j < n;j++){
		int k; cin>>k;
		for(int i = 0;i < k;i++){
			int w, t; cin>>w>>t;
			
		}
	}
	while(q--){
		int x, y;
		cin>>x>>y;
	}
}
