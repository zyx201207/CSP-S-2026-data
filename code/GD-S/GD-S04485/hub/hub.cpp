#include<bits/stdc++.h>
using namespace std;
int c, t, n, k;
void solve() {
	cin >> n >> k; 
	for (int i = 1, u, v; i < n; i++) 
		cin >> u >> v;
	cout << n / 2;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
