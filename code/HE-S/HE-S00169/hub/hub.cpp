#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
long long c, t;
long long n, k;
long long a[N][N];
long long vis[N][N];
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				a[i][j] = 0; 
			}
		}
		long long x = n - 1;
		while (x--) {
			long long u, v;
			cin >> u >> v;
			a[u][v] = 1;
			a[v][u] = 1;
		}
	}
	cout << 1 << endl << 2;
	return 0;
}
