#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5, M = 3e5 + 5;

int a[N];
int ans[M];
bool ban[M];
bool vis[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	map<int, int> mp;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = n; i >= 1; --i) {
		vis[a[i]] = false;
		memset(ban, 0, sizeof(ban));
		for (int j = 1; j <= m; ++j) {
			if (vis[j]) {
				--ans[j];
				ban[j] = true;
			}
		}
		if (mp.find(a[i]) == mp.end()) {
			mp[a[i]] = i;
			ans[a[i]] = i;
		} else {
			for (int j = i + 1; j < mp[a[i]]; ++j) {
				if (mp[a[j]] == n || a[j] == a[i]) continue;
				if (ban[a[j]]) continue;
				ans[a[j]]--;
				ban[a[j]] = true;
				vis[a[j]] = true;
			}
		}
	}
	for (int i = 1; i <= m; ++i) {
		cout << ans[i] << " ";
	}
	cout << '\n';
	return 0;
}
