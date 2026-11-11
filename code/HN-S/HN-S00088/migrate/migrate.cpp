#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int c, t;
int n, d;
int a[N];
// pair <int, long long> f[N][N];
int ans, cnt;
long long ToT;
void dfs(int p, int s, int e, int sum) {
	ToT++;
	if (p == e) {
		//cout << p << ' ' << s << ' ' << e << ' ' << sum << ' ' << cnt << '\n';
		if (sum == ans) cnt++;
		else if (sum < ans) return ans = sum, cnt = 1, void();
		else return;
	}
	for (int i=p+1; i<=e; i++) 
		if (a[i] - a[p] <= d)
			dfs(i, s, e, sum + 1);
}
bool judge(int s, int e) {
	ans = 0x3f3f3f3f;
	dfs(s, s, e, 0);
	if (cnt == 2 && ans != 0x3f3f3f3f) { 
	//	cout << "::::::" << s << ' ' << e << ' ' << ans << '\n'; 
		return true;
	}
	else return false;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i=1; i<=n; i++) cin >> a[i];
		/*
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++) {
				int k = abs(a[j] - a[i]);
				if (k <= d) f[i][j] = {k, 1};
				else f[i][j] = {0x3f3f3f3f, 1};
			}
		for (int k=1; k<=n; k++)
			for (int i=1; i<=n; i++)
				for (int j=1; j<=n; j++) {
					if (i == j || i == k || j == k) continue;
					if (f[i][k].first + f[k][j].first < f[i][j].first) {
						f[i][j].first = f[i][k].first + f[k][j].first;
						f[i][j].second = f[i][k].second * f[k][j].second;
						cout << i << ' ' << k << ' ' << j << ' ' << f[i][j].first << ' ' << f[i][j].second << '\n';
					} else if (f[i][k].first + f[k][j].first == f[i][j].first) {
						f[i][j].second++;
						cout << i << ' ' << k << ' ' << j << ' ' << f[i][j].first << ' ' << f[i][j].second << '\n';
					}
				}
		long long res = 0;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++) {
				//cout << f[i][j].second << ' ';
				if (f[i][j].second == 2) {
					cout << i << "->" << j << '\n';
					res++;
				}
			}
		cout << res << '\n';
		*/
		long long res = 0;
		for (int i=1; i<=n; i++)
			for (int j=i+1; j<=n; j++)
				res += judge(i, j);
		cout << res << '\n';
	}
//	cout << ToT;
	return 0;
}
