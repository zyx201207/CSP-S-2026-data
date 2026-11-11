#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> G[100010];

void solve(){
	memset(G, 0, sizeof(G));
	cin >> n >> k;

	if(k == 2){
		for(int i = 0; i < n; i ++){
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
	}
}

int main(){
	int c, t;
	cin >> c >> t;
	while(t --) solve();
	return 0;
}
