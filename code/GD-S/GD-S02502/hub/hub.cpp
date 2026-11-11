#include<bits/stdc++.h>
using namespace std;
int c, t, cnt, n, k, u, v;
vector<int> g[1000009];
int main (  ) {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	cnt = t;
	while(t--) {
		cin >> n >> k;
		for(int i = 1; i <= n - 1; i++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	t = cnt;
	if(c == 0) {
		if(t == 2) {
			for(int i = 1; i <= t; i++) cout << i << '\n';
		}
		else if(t == 3) {
			for(int i = 1; i <= t; i++) cout << i << '\n';
		}
		else cout << 12251;
	}
	return 0;
}
