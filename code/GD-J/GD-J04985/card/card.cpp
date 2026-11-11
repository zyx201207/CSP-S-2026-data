#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m; vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
	
	vector<int> ans(m);
	for (int i = 0; i < n; i++) {
		vector<int> vis(m); stack<int> stk;
		for (int j = i; j < n; j++) {
			if (!vis[a[j]]) {
				vis[a[j]] = true;
				stk.push(j);
				continue; 
			}
			while (!stk.empty()) {
				int k = stk.top(); stk.pop();
				vis[a[k]] = false;
				if (a[k] == a[j]) break;
			}
			vis[a[j]] = true, stk.push(j);
		}
		
		while (!stk.empty()) {
			int k = stk.top(); stk.pop();
			ans[a[k]]++;
		}
	}
	for (int i = 0; i < m; i++) cout << ans[i] << " \n"[i == m - 1];
	return 0;
}

