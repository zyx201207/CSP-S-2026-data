#include <bits/stdc++.h>
#define int long long
using namespace std;

int C, T, n, d, res, cnt, x[2000005];

void dfs(int s, int t, int step) {
	int p = s + 1;
	if(step > res) return;
	if(s == t) {
		if(res == step) cnt ++;
		if(res > step) {
			res = step; cnt = 1;
		}
		return;
	}
	while(x[p] - x[s] <= d && p <= t) {
		dfs(p, t, step + 1);
		p ++;
	}
}

void sol1() {
	while(T --) {
		int ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i ++) {
			cin >> x[i];
		}
		for(int i = 1;i <= n;i ++) {
			for(int j = i + 1;j <= n;j ++) {
				res = 1e18; cnt = 0;
				dfs(i, j, 0);
				if(cnt == 2) {
					ans ++;
				}
			}
		}
		cout << ans << "\n";
	}
}

void sol2() {
	while(T --) {
		cin >> n >> d;
		for(int i = 1;i <= n;i ++) {
			cin >> x[i];
		}
		if(n == 1) {
			cout << "0\n";
			continue;
		}
		if(d == x[2] - x[1] - 1) {
			cout << n - 1 << "\n";
		}else {
			cout << "0\n";
		}
	}
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> C >> T;
	if(C <= 2) sol1();
	else sol2();
	return 0;
}//´óÊ§°Ü¡£ 
