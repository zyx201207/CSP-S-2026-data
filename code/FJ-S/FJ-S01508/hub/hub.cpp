#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t;
int n, k;
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 1; i <= n; i++) {
			int u, v;
			cin >> u >> v;
		}
		n /= 2;
		n++;
		cout << (n-k)/4+1 << "\n";
	}
	return 0;
}
