#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define file(s)	freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)
const int N = 2e5 + 10;
int n, m, a[N], vis[N][31];
vector<int> bit[31];
void init(int x, int idx) {
	int val = (1 << 30);
	for (int b = 30; b >= 0; --b) {
		if (x >= val)	vis[idx][b] = 1, x -= val;
		val >>= 1;
	}
}
signed main() {
	file(and);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		init(a[i], i);
	}
	vector<int> vec;
	for (int i = 1; i <= n; ++i)	vec.push_back(i);
	for (int b = 30; b >= 0; --b) {
		for (int x : vec)	if (vis[x][b])	bit[b].push_back(x);
		if (bit[b].size() >= m) {
			vec.clear();
			for (int x : bit[b])	vec.push_back(x);
		}
	}
	for (int b = 0; b <= 30; ++b) {
		if (bit[b].size() >= m) {
			int ans = a[bit[b][0]];
			for (int j = 1; j < m; ++j)	ans &= a[bit[b][j]];
			cout << ans;
			return 0;
		}	
	}
	cout << 0;
	return 0;
}
