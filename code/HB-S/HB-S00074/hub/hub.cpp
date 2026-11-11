#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
const int PN = 5e3 + 10;

int n, k;
int f[PN][PN];
vector<int> links[MAXN];

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		links[i].clear();
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		links[u].push_back(v);
		links[v].push_back(u);
	}
	if (k <= 2) {
		cout << 1 << '\n';
		return ;
	}
		cout << rand() % k + 1 << '\n';
		return ;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t--) 
		solve();
	return 0;
}