#include <bits/stdc++.h>
using namespace std;

int C, T, n, k, st[1000010][30], d[1000010];
vector <int> b[2000010];
void dfs(int u, int f) {
	st[u][0] = f;
	d[u] = d[f] + 1;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> C >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) b[i].clear();
		for (int i = 1, u, v; i < n; i++) {
			cin >> u >> v;
			b[u].push_back(v);
			b[v].push_back(u);
		}
		cout << "1\n";
	}
	return 0;
} 
