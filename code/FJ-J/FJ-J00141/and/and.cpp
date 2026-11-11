#include <bits/stdc++.h>
using namespace std;

vector<int> a[35];
int n, m;

int dfs(vector<int> b[35], int k, int ans) {
	vector<int> c[35];
	for (int x : b[k]) {
		bitset<40> t(x);
		for (int i = 34; i >= 0; i--) if (t[i]) c[i + 1].push_back(x);
	}
	
	for (int i = k - 1; i >= 1; i--) {
		if (c[i].size() == m) {
			ans = c[i][0];
			for (int x : c[i]) ans &= x;
			return ans;
		}
		
		if (c[i].size() > m) {
			ans = c[i][0];
			for (int x : c[i]) ans &= x;
			return dfs(c, i, ans);
		}
	}
	
	return ans;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		bitset<40> t(x);
		for (int j = 34; j >= 0; j--) if (t[j]) a[j + 1].push_back(x);
	}
	
	for (int i = 35; i >= 1; i--) {
		if (a[i].size() == m) {
			int ans = a[i][0];
			for (int x : a[i]) ans &= x;
			cout << ans;
			return 0;
		}
		
		if (a[i].size() > m) {
			int ans = a[i][0];
			for (int x : a[i]) ans &= x;
			cout << dfs(a, i, ans);
			return 0;
		}
	}
	
	return 0;
}
