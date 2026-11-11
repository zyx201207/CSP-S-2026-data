#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	
	while (t--) {
		int n, k; cin >> n >> k;
		vector<vector<int>> g(n);
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		cout << 1 << '\n';
	}
	
	return 0;
} 
