#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int n, d, a[N], c;
int r_to[24][N], l_to[24][N], r_sum[24][N], l_sum[24][N];
void clear() {
	for (int i = 1; i <= 22; i++) {
		for (int j = 1; j <= n; j++) {
			r_to[i][j] = r_sum[i][j] = l_to[i][j] = l_sum[i][j] = 0;
		}
	}
}
int qryr(int l, int r) {
	int res = l;
	for (int i = 22; i >= 0; i--) {
		if (r_to[i][l] != 0 && r_to[i][l] < r) {
		//	cout << l << ' ' << i << '\n';
			res += r_sum[i][l];
			l = r_to[i][l];
		}
	}
	if (a[r] - a[l] > d) return 0;
	return res + r;
}
int qryl(int l, int r) {
//	cout << l << "  " << r << '\n';
	int res = r;
	for (int i = 22; i >= 0; i--) {
		if (l_to[i][r] > l) {
			res += l_sum[i][r];
			r = l_to[i][r];
		}
	}
//	cout << l << ' ' << r << '\n';
	if (a[r] - a[l] > d) return 0;
	return res + l;
}
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i]; 
	int j = 1;
	for (int i = 1; i <= n; i++) {
		while (j <= i) j++;
		while (j < n && a[j + 1] - a[i] <= d) j++;
		if (j == n + 1 || a[j] - a[i] <= d) {
			r_to[0][i] = j;
			r_sum[0][i] = j;
		} else {
			r_to[0][i] = i;
			r_sum[0][i] = i;
		}	
	//	cout << i << ' ' << j << '\n';
	}
	r_to[0][n + 1] = n + 1;
	j = n;
	for (int i = n; i >= 1; i--) {
		while (j >= i) j--;
		while (j > 1 && a[i] - a[j - 1] <= d) j--;
		if (j == 0 || a[i] - a[j] <= d) {
			l_to[0][i] = j;
			l_sum[0][i] = j;
		} else {
			l_to[0][i] = i;
			l_sum[0][i] = i;
		}
	}
	for (int i = 1; (1 << i) <= n; i++) {
		for (int j = 1; j <= n; j++) {
			r_to[i][j] = r_to[i - 1][r_to[i - 1][j]];
		//	cout << i << ' ' << j << ' ' << r_to[i][j] << '\n';
			r_sum[i][j] = r_sum[i - 1][j] + r_sum[i - 1][r_to[i - 1][j]];
			l_to[i][j] = l_to[i - 1][l_to[i - 1][j]];
			l_sum[i][j] = l_sum[i - 1][j] + l_sum[i - 1][l_to[i - 1][j]];
		}
	}
	int ans = 0;
	if (c == 11 || c == 12) {
		int j = 1;
		for (int i = 1; i <= n; i++) {
			while (j <= i) j++;
			while (j <= n && qryr(i, j) - qryl(i, j) != 1) j++;
			if (j <= n) ans++;
		}
		cout << ans << '\n';
		clear();
		return ;
	}
	int st = 0;
	for (int i = 1; i <= n; i++) {
		int flag = 0;
		st = max(i + 1, st);
		vector<int> vec;
		for (int j = st; j <= n; j++) {
		//	cout << i << ' ' << j << ' ' << qryr(i, j) << '\n';
			if (qryr(i, j) - qryl(i, j) == 1) {
				if (!flag) st = max(st, j);
				flag = 1;
				vec.push_back(j);
				ans++;
			}
		}
		//if (vec.size()) {
		//	cout << i <<"  "<< vec.front() << ' ';
		//	for (int j = 1; j < vec.size(); j++) cout << vec[j] - vec[j - 1] << ' ';
		//	cout << endl;
		//}
	}
	cout << ans << '\n';
	clear();
}
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
	int T;
	cin >> c >> T;
	while (T--) solve();
	return 0;
} 
