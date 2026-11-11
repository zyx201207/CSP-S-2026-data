#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	vector<int> ans(m + 1, 0);
	for(int i = 1; i <= n; i++) cin >> a[i];
	unordered_map<int, int> mp;
	vector<int> cnt(m + 1, 0);
//	cout << "NO RE\n";
	
	vector<int> order;
	for(int i = n; i >= 1; i--) {
		cnt[a[i]]++;
		if(!mp.count(a[i])) {
			order.push_back(i);
			mp[a[i]] = 1;
			continue;
		}
	}
	
//	for(int i : order) cout << i << ' ';
//	cout << '\n';
	
	vector<vector<int>> t(m + 1, vector<int>(m + 1, 0));
//	cout << "NO RE\n";

	for(int i : order) {
		if(i == n) {
			t[a[i]][a[i]]++;
			continue;
		}
		t[a[i]] = t[a[i + 1]];
		t[a[i]][a[i]]++;
	}
	
//	for(int i = 1; i <= m; i++) {
//		for(int j = 1; j <= m; j++) {
//			cout << t[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << '\n';
	
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= m; j++) {
			ans[j] += t[i][j] * cnt[i];
		}
	}
	
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
	
	return 0;
}
