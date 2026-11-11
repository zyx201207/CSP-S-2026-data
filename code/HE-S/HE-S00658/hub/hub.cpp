#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 5;
int c, t;
int n, k;
vector<int> ed[N];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			int u, v;
			cin >> u >> v;
			ed[u].push_back(v);
			ed[v].push_back(u);
		}	
	}
	return 0;
}

