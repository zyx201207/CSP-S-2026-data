#include <iostream>
#include <algorithm>
#define endl '\n'
#define int long long
using namespace std;

const int N = 2e6 + 5;

int n, d, a[N], tot, minn;

void dfs(int u, int ed, int cnt) {
	if(a[u] > a[ed]) return;
	if(u == ed) {
		if(cnt < minn) {
			tot = 1;
			minn = cnt;
		}
		else if(minn == cnt) tot++;
	}
	for(int i = u + 1; i <= n; i++) {
		if(a[i] > a[ed] || a[i] - a[u] > d) break;
		dfs(i, ed, cnt + 1);
	}
}

signed main() {//16~24pts
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		if(c == 11 || c == 12) {
			int t = a[2] - a[1];
	//		cout << n << ' ' << d << ' ' << t << endl;
			if(d >= 2 * t && d / t < n) cout << n - 2 * (d / t) + 1 << endl;
			else cout << 0 << endl;
		}
		else if(c <= 2) {
			int cnt = 0;
			for(int i = 1; i <= n; i++) {
				for(int j = i + 1; j <= n; j++) {
					tot = 0;
					minn = 1e9;
					dfs(i, j, 0);
					if(tot == 2) {
//						cout << i << ' ' << j << endl;
						cnt++;
					}
				}
			}
			cout << cnt << endl;
		}
		else cout << 0 << endl;
	}
	return 0;
}
/*
0 1
10 7
1 3 5 6 7 9 10 11 13 14
*/
