#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll INF = 4e18;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t; cin >> c >> t;
	while (t--) {
		ll ans = 0;
		int n, d; cin >> n >> d;
		vector<ll> x(n);
		for (int i = 0; i < n; i++) cin >> x[i];
		
		for (int i = 0; i < n - 1; i++) {
			vector<ll> dis(n, INF);
			vector<ll> cnt(n, 0);
			queue<int> q;
			dis[i] = 0;
			q.push(i);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				for (int v = u + 1; v < n; v++) {
					if (x[v] - x[u] > d) break;
					if (dis[v] == INF) dis[v] = dis[u] + 1, q.push(v);
					if (dis[u] + 1 == dis[v]) {
						cnt[v]++;
//						cout << "u=" << u << ", v=" << v << '\n';
					}
				}
			}
			
//			cout << "i: " << i << '\n';
			for (int j = 0; j < n; j++) {
//				cout << j << " " << cnt[j] << '\n';
				if (cnt[j] == 2) ++ ans; 
			}
		}
		
		cout << ans << '\n';
	}
	
	return 0;
} 
