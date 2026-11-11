#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[200010], ans;
void dfs(int k, int num, int cnt) {
	if(k == n + 1) {
		if(num != pow(2, 20) - 1 && cnt == m) ans = max(ans, num);
		return ;
	}
	dfs(k + 1, (num & a[k]), cnt + 1);
	dfs(k + 1, num, cnt);
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if(n <= 20) {
		dfs(1, pow(2, 20) - 1, 0);
		cout << ans;
	}
	else if(m == 1) {
		int ma = 0;
		for(int i = 1; i <= n; i++) {
			ma = max(ma, a[i]);
		}
		cout << ma;
	}
	else if(m == n) {
		int num = pow(2, 20) - 1;
		for(int i = 1; i <= n; i++) {
			num &= a[i];
		}
		cout << num;
	}
	else if(m == 2) {
		int ma = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				ma = max(ma, (a[i] & a[j]));
			}
		}
		cout << ma;
	}
	else {
		cout << 1;
	}
	return 0;
}
/*
5 3
31 3 1 15 7
*/
