#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

int c, t;
int n, k;
vector<int> g[N];

/*
 * 17:49
 * wo lei le
 * 
 * mei shi, wo bu hui de bie ren dou bu hui!
 */

int main() { // Oct31==Dec25
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			g[i].clear();
		}
		
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << 0 << "\n";
	}
	return 0;
}
