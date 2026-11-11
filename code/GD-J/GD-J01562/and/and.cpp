#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<vector<int>> bin(n, vector<int>(40, 0));
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		int t = a[i];
		int cnt = 0;
		while (t) {
			bin[i][cnt++] = t & 1;
			t >>= 1;
		}
	}
	vector<bool> ch(n);
	bool flag = false;
	for (int i = 35; i >= 0; --i) {
		int cnt = 0;
		vector<bool> vis(n);
		for (int j = 0; j < n; ++j) {
			if (bin[j][i] == 1 && ((!flag) || ch[j] == true)) {
				cnt++;
				vis[j] = true;
			}
		}
		if (cnt >= m) {
			ch = vis;
			flag = true;
		}
	}
	int res = (1LL << 31) - 1;
	for (int i = 0; i < n; ++i) {
		if (ch[i]) res &= a[i];
	}
//	for (int i = 0; i < n; ++i) {
//		cout << ch[i] << " ";
//	}
	cout << res << endl;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
