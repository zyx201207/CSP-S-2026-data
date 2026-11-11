#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 1005;
const int inf = 0x3f3f3f3f;
int c, t;
vector<int> G[N];
ll dis[N][N];
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	for (int s {1}; s <= t; ++s) {
		int n, k;
		cin >> n >> k;
		for (int i {1}; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			G[u].emplace_back(v);
			G[v].emplace_back(u);
		}
	}
	for (int i {1}; i <= t; ++i) {
		cout << i << '\n';
	}
	return 0;
}
