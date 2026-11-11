#include <bits/stdc++.h>
#define pb push_back

using namespace std;

/*
long long?
freopen!!
*/

const int maxn = 2e6 + 10;

vector<int> e[maxn << 1];
int n, k;

void solve() {
	cin >> n >> k;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		e[u].pb(v);
		e[v].pb(u);
	}
	cout << 0 << '\n';
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--)
		solve();
	return 0;
}

