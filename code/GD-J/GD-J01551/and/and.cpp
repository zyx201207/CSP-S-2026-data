#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Max(a, b) a = max(a, b)
const int N = 2e5 + 5;
int n, m, a[N], dp[N], vis[N];
vector<int> g[35], nw;
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 0; j < 30; j++)
			if ((a[i] >> j) & 1ll) g[j].push_back(i);
	}
	for (int i = 29; i >= 0; i--) {
		if (g[i].size() < m) continue;
		if (nw.empty()) {
			nw = g[i];
			continue;
		}
		vector<int> hf; 
		memset(vis, 0, sizeof vis);
		for (int j : nw) vis[j]++;
		for (int j : g[i]) 
			if (vis[j]) hf.push_back(j);
		if (hf.size() < m) continue;
		nw = hf;
	}
	if (nw.empty()) {
		cout << 0;
		return 0;
	}
	int sum = (1ll << 30) - 1;
	for (int i : nw) sum &= a[i];
	cout << sum;
  	return 0;
}
/*
4 2
3 15 12 12
0 : 2
1 : 2
2 : 3
3 : 3
*/
