# include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	
	while (t--) {
		int n, d;
		cin >> n >> d;
		
		int maxn = 0;
		
		vector<int> x(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
		}
		
		int cnt = INF;
		
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				int distance = abs(x[i] - x[j]);
				
				cnt = min(cnt, distance / d);
			}
		}
		
		int result = 0;
		
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				int distance = abs(x[i] - x[j]);
				
				if (distance / d == cnt) {
					result++;
				}
			}
		}
		
		cout << result << '\n';
	}
	
	return 0;
}
