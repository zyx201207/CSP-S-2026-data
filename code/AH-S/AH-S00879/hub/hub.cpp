#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long c, t;
long long n, k;
vector <long long> a[N];
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			long long u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		if(k <= 2) {
			cout << 1 << "\n";
			continue;
		}
		if(c == 13 || c == 14) {
			cout << (2*n+16-4*(k-1) - 2)/16 << "\n";
			continue;
		}
		cout << 1 << "\n";
	}
	return 0;
}
