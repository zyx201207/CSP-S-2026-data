#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, m, a[200005], maxn;
void dfs(int step, int sum, int last) {
	if(n - last < (m - step)) return;
	if(step >= m) {
		maxn = max(maxn, sum);
		return;
	}
	for(int i = last+1; i <= n; i++) {
		int x = (sum & a[i]);
		dfs(step + 1, x, i);
	}
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n - m + 1; i++) {
		dfs(1, a[i], i);
	}
	cout << maxn;
	return 0;
} 
