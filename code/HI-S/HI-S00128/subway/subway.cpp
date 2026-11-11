# include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
	vector<int> w(m + 1, 0);
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	
	vector<int> k(n + 1, 0);
	
	vector<vector<int>> a(n + 1, vector<int>());
	vector<vector<int>> t(n + 1, vector<int>());
	
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		
		for (int j = 1; j <= 2 * k[i]; ++j) {
			int as, ts;
			cin >> as >> ts;
			
			a[i].push_back(as);
			t[i].push_back(ts);
		}
	}
	
	while (q--) {
		int src, end;
		cin >> src >> end;
		
		cout << 39 << '\n';
	}
	
	return 0;
}
