#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int c, n, m, d, q, k;
int w[MAXN], dist[MAXN];


int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	
	vector<vector<pair<int, int>>> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int v, t;
			cin >> v >> t;
			a[i].emplace_back(v, t);
		}
	}
	
	while(q--) {
		int s, t;
		cin >> s >> t;
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<int>> pq;
		pq.push();
		cout << 1 << endl;
	}
}
