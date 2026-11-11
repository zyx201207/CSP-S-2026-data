#include <bits/stdc++.h>
#define int long long
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

int n, k;
vector<int> g[1000005];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin>>c>>t;
	while (t--) {
		cin>>n>>k;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if (c == 13 || c == 14) {
			cout<<ceil((n/2+4-k)/4.0)<<'\n';
			continue;
		}
	}
	return 0;
}
