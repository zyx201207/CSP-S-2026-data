#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int a[N];
int ans[M];
bool vis[M];
int n, m;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	if (m == 2) {
		int ans1 = 0, ans2 = 0;
		if (a[n] == 2) ans2 = n;
		else ans1 = n;
		for (int i = 1; i <= n; i++) {
			if (a[n] == 2 && a[i] == 1) ans1++;
			if (a[n] == 1 && a[i] == 2) ans2++;
		}
		cout << ans1 << " " << ans2;
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		memset(vis, 0, sizeof vis);
		vector<int> arr;
		for (int j = i; j <= n; ++j) {
			if (!vis[a[j]]) {
				arr.push_back(a[j]);
				vis[a[j]] = 1;
			}
			else {
				while (arr[arr.size() - 1] != a[j] && !arr.empty()) vis[arr[arr.size() - 1]] = 0, arr.pop_back(); 
			}
		}
		for (auto& e : arr) ans[e]++;
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
