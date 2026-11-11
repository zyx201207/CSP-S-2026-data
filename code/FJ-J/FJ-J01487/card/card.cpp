#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	vector<int> a(n);
	vector<bool> vis(m);
	vector<int> pre(m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	vector<int> ans(m + 1, 0);
	for(int i = 0; i < n; i++) {
		int l = n / 2, r = n / 2 + 1;
		for(int j = i; j < n; j++) {
			bool flag = false;
			for(int k = n - 1; k >= j; k--) {
				if (a[j] == a[k]) {
					l = j, r = k + 1;
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		vector<bool> apr(m + 1, false);
		for(int j = i; j <= l; j++) {
			apr[a[j]] = true;
		}
		for(int j = r; j < n; j++) {
			apr[a[j]] = true;
		}
		for(int j = 1; j <= m; j++) {
			ans[j] += apr[j];
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}
