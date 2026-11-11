#include<bits/stdc++.h>
using namespace std;
int n, m, a[500001], ans[500001], inve[500001];
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	} 
	if (n <= 5000) {
		for (int i = 1; i <= n; i++) {
			fill(inve + 1, inve + m + 1, 0); 
			vector <int> ve;
			for (int j = i; j <= n; j++) {
				if (!inve[a[j]]) {
					inve[a[j]]++;
					ve.push_back(a[j]);
				} else {
					while (ve.back() != a[j]) {
						inve[ve.back()]--;
						ve.pop_back();
//						cerr << ve.size() << ' ';
					}
				}
			}
			for (auto x : ve) {
				ans[x]++;
			}
		}
		for (int i = 1; i <= m; i++) {
			cout << ans[i] << ' ';
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if (a[i] != a[i + 1]) {
				cout << i << ' ';
			}
		}
	}
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--) {
		solve();
	}
} 

/*

打个暴力和特殊性质，跑路 

*/
