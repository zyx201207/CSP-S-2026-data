#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	int c, t;
	cin >> c >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> G[n + 1];
		for(int i = 1; i <= n; i++){
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}
	return 0;
}
