#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int cas, twt;
int n, k, u, v;
vector<int> g[N];
void solve() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> cas >> twt;
	while (twt--) solve();
}
