#include <bits/stdc++.h>
using namespace std;

int c, T, n, k, d[1000006], mx;
vector <int> g[1000006];

int main () {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	
	cin >> c >> T;
	while (T --) {
		cin >> n >> k;
		for (int i = 1; i < n; i ++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back (v);
			g[v].push_back (u);
			d[u] ++, d[v] ++;
			mx = max (d[u], mx);
			mx = max (d[v], mx);
		}
		if (c == 13 || c == 14 || c == 0) {
			if (k >= n / 2) {cout << "2\n"; continue;}
			int p = n / 2 + 1;
			if (p % 2) cout << (p + 1) / 2 - (k + 1) / 2 << "\n";
			else cout << p / 2 + 1 - k / 2 << "\n";
			continue;
		}
		if (n <= 5) {
			if (mx < 4) cout << 1;
			else cout << 2;
			cout << "\n";
			continue;
		}
	}
	return 0;
}
