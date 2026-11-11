#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[200001], m;
bool f[200001];
int mx = -1e9;
void dfs(int d, int x) {
	if(d >= m) {
		mx = max(mx, x);
		return ;
	}
	for(int i = 1;i <= n;++i) {
		if(f[i] == 0) {
			f[i] = 1;
			dfs(d + 1, x & a[i]);
			f[i] = 0;
		} 
	}
	return ;
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
	}
	
	dfs(0, 4611686018427387903);
	cout << mx;
	return 0;
}
