#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans[200007], a[200007], res = INT_MIN, maxn = INT_MIN;
bool vis[200007];

bool check(int num) {
	int z = 0;
	int num1 = num+1;
	while (num1) {
		num1 /= 2;
		z++;
	}
	return pow(2, z-1) == num+1;
}

bool checkb() {
	int z = 0;
	int num1 = n;
	while (num1) {
		num1 /= 2;
		z++;
	}
	bool f = pow(2, z-1) == n;
	if (!f) return false;
	for (int i = 1; i <= n; i++) {
		if (a[i] != i-1) return false;
	}
	return true;
}

bool checka() {
	for (int i = 1; i <= n && i <= 100; i++) {
		if (check(a[i]) == false) return false;
	}
	return true;
}

void dfs(int step) {
	if (step == m) {
		int andd = ans[1];
		for (int i = 0; i < m; i++) {
			andd &= ans[i];
//			cout << ans[i] << ' ';
		}
//		cout << andd<<'\n';
//		cout << '\n';
		res = max(res, andd);
	}
	for (int i = step+1; i <= n; i++) {
		if (vis[i] == false) {
			ans[step] = a[i];
			vis[i] = true;
			dfs(step+1);
			vis[i] = false;
		}
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	if (m == n) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	if (m == 1) {
		cout << maxn;
		return 0;
	}
	if (checka()) {
		sort(a+1, a+1+n, greater<int>());
		cout << a[m];
		return 0;
	}
	if (checkb()) {
		cout << a[m+1];
		return 0;
	}
	sort(a+1, a+1+n);
	dfs(0);
	cout << res;
	
	return 0;
}
