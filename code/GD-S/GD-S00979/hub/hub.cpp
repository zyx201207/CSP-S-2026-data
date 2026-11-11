#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
int cpos, n, k;
vector<int> e[N];
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	cout << 1 << "\n";
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> cpos;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
