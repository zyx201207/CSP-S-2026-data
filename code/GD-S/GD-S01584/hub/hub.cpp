#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int>e[maxn];
		for(int i = 0; i < n - 1; i++){
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
	}
	return 0;
}
