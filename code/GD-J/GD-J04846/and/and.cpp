#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a;
bool v[200005];
int n, m, bs;
int k = 0;
void dfs(int ans, int d) {
	//cout << ans << ' ' << d << endl;
	if(d >= m) {
		k = max(k, ans);
		return;
	}
	for(int i = 0; i < a.size(); i++) {
		if(v[i])
			continue;
		int o = a[i];
		v[i] = 1;
		if(d == 0)
			dfs(o, d + 1);
		else
			dfs(ans & o, d + 1);
		v[i] = 0;
	}
	return;
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		a.push_back(t);
	}
	dfs(0, 0);
	cout << k;
}

