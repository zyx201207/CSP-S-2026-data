#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], mx;
void dfs(int x, int cnt, int s) {
	if(cnt > m) return ;
	if(x > n) {
		if(cnt == m) mx = max(mx, s);
		return ;
	}
	dfs(x + 1, cnt + 1, s & a[x]);
	dfs(x + 1, cnt, s);
}
bool chk(int x) {
	bool res = 1;
	while(x) {
		res &= (x & 1);
		x >>= 1;
	}
	return res;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n <= 20) {
		dfs(1, 0, (1 << 30) - 1);
		cout << mx;
	}
	else if(n > 20 && n <= 2000) {
		if(m == 1) {
			for(int i = 1; i <= n; i++) mx = max(mx, a[i]);
			cout << mx;
		}
		else if(m == 2) {
			for(int i = 1; i <= n; i++) {
				for(int j = i + 1; j <= n; j++)
					mx = max(mx, a[i] & a[j]);
			}
			cout << mx;
		}
		else if(m == n) {
			mx = (1 << 30) - 1;
			for(int i = 1; i <= n; i++) mx &= a[i];
			cout << mx;
		}
	}
	else if(n > 2000) {
		int cnt = 0;
		vector<int> g;
		for(int i = 1; i <= n; i++) {
			if(chk(a[i])) cnt++, mx = max(mx, a[i]);
			else g.push_back(a[i]);
		}
		if(cnt >= m - 1) cout << mx;
		else {
			m -= cnt;
			sort(g.begin(), g.end(), [](int x, int y) {return x > y;});
			mx = (1 << 30) - 1;
			for(int i = 0; i < m; i++) mx &= g[i];
			cout << mx;
		}
	} 
	return 0;
}
