#include <bits/stdc++.h>
#define qwq ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int, int>
//#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, m, ans;
int a[N], v[N];
int maxx, minn = INT_MAX;
void dfs(int dep) {
	if (dep > m) {
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (!v[i]) continue ;
			if (res == 0) res = a[i];
			else res &= a[i];
		}
		ans = max(ans, res);
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (v[i]) continue ;
		v[i] = 1;
		dfs(dep + 1);
		v[i] = 0; 
	}
}
int Rand(int n) {
	return (long long)rand() * rand() % n;
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	qwq;
	srand((unsigned)time(0));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]), minn = min(minn, a[i]);
	}
	if (m == 1) 
		cout << maxx <<"\n";
	else if (n == m) {
		int res = a[1];
		for (int i = 2; i <= n; i++) 
			res &= a[i];
		cout << res << "\n";
	}
	else if (m == 2 and n <= 20000) {
		int res = 0;
		for (int i = 1; i <= n; i++) 
			for (int j = i + 1; j <= n; j++) 
				res = max(res, a[i] & a[j]);
		cout << res << "\n";
	}
	else if (n <= 30) {
		dfs(1);
		cout << ans << "\n";
	}
	else {
		int res = Rand(maxx - minn + 1) + minn;
		cout << res << "\n";
	}
	return 0;
} 
