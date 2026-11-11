#include<bits/stdc++.h>
using namespace std;
int c, t, n, sum;
long long d, cnt, ans, x[2000009], dist[2000009], mi[500009];
vector<pair<int, int>> g[2000009];
int main (  ) {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for(int j = 1; j <= t; j++) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) {
			cin >> x[i];
			for(int j = i - 1; j > 0; j--) {
				if(x[i] - x[j] <= d) {
					g[j].push_back({i, x[i] - x[j]});
					g[i].push_back({j, x[i] - x[j]});
				}
				else break;
			}
		}
		cout << j << '\n';
	}
	return 0;
}
