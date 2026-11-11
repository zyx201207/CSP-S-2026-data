#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
int cc, t;

int main(){
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	cin.tie (nullptr) -> sync_with_stdio (false);
	cin >> cc >> t;
	while (t--){
		int n;
		long long d, ans = 0;
		cin >> n >> d;
		vector <long long> a (n + 1);
		for (int i = 1; i <= n; i++){
			cin >> a [i];
		}
		if (n > 10){
			long long k = d / (a [2] - a [1]);
			if (k <= 1){
				cout << 0 << '\n';
			}
			else {
				cout << max (n - 2 * k + 1, 0ll) << '\n';
			}
			continue;
		}
		vector <vector <pair <int, int> > > g (n + 1, vector <pair <int, int> > (n + 1, {0, 1e9}));
		auto dfs = [&] (auto&& self, int pos, int b, int cnt) -> void
		{
			if (cnt < g [b][pos].second){
				g [b][pos].first = 1, g [b][pos].second = cnt;
			}
			else if (cnt == g [b][pos].second){
				g [b][pos].first++;
			}
			for (int i = pos + 1; i <= n; i++){
				if (a [i] - a [pos] > d){
					break;
				}
				self (self, i, b, cnt + 1);
			}
		};
		for (int i = 1; i <= n - 1; i++){
			dfs (dfs, i, i, 0);
		}
		for (int i = 1; i <= n; i++){
			for (int j = i + 3; j <= n; j++){
				if (g [i][j].first == 2){
					ans++;
				}
			}
		}
		cout << ans << '\n';
	} 
	return 0;
}
