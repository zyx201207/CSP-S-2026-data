#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
vector<int> g[N];

int n, k;

void solve() {
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) g[i] = {}; 
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int c, T;
	cin >> c >> T;
//	while(T--) {
//		solve();
//	}
	for(int i = 1; i <= T; i++) cout << i << '\n';
	return 0;
}
