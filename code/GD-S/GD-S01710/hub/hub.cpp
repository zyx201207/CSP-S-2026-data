#include <bits/stdc++.h>
using namespace std;

int cc, t;

int main(){
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	cin.tie (nullptr) -> sync_with_stdio (false);
	cin >> cc >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		vector <vector <int> > dp (n + 1, vector <int> (n + 1, 1e9));
		for (int i = 1; i <= n - 1; i++){
			int u, v;
			cin >> u >> v;
			dp [u][v] = dp [v][u] = 1;
		}
		for (int i = 1; i <= n; i++){
			dp [i][i] = 0;
		}
		for (int l = 1; l <= n; l++){
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++){
					dp [i][j] = min (dp [i][j], dp [i][l] + dp [l][j]);
				}
			}
		}
		vector <int> p (n + 1);
		for (int i = 1; i <= n; i++){
			p [i] = i;
		}
		int ans = 1e9;
		do {
			vector <int> f (n + 1), s (n + 1);
			for (int i = 1; i <= n; i++){
				f [i] = i, s [i] = 1;
			}
			auto find = [&] (auto&& self, int x) -> int
			{
				if (f [x] == x){
					return x;
				}
				else {
					return f [x] = self (self, f [x]);
				}
			};
			auto merge = [&] (int x, int y) -> void
			{
				x = find (find, x), y = find (find, y);
				if (x == y){
					return;
				}
				if (s [x] > s [y]){
					swap (x, y);
				}
				f [x] = y;
				s [y] += s [x];
			};
			for (int i = 1; i <= k; i++){
				for (int j = i + 1; j <= k; j++){
					if (dp [p [i]][p [j]] == 1){
						merge (p [i], p [j]);
					}
				}
			}
			vector <int> vis (n + 1);
			int sum = 0;
			for (int i = 1; i <= k; i++){
				if (vis [f [p [i]]] == 0){
					vis [f [p [i]]] = 1;
					sum++;
				}
			}
			if (sum > 2){
				continue;
			}
			int ans1 = 0;
			for (int i = 1; i <= n; i++){
				int ans2 = 1e9;
				for (int j = 1; j <= k; j++){
					ans2 = min (ans2, dp [i][p [j]]);
				}
				ans1 = max (ans1, ans2);
			}
			ans = min (ans, ans1);
		} while (next_permutation (p.begin () + 1, p.begin () + n + 1));
		cout << ans << '\n';
	}
	return 0;
}
