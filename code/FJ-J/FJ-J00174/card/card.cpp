#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector <int> a(n + 1), now(n + 1);
	vector <int> ans(m + 1);
	for (int i = 1;i <= n;i++) cin >> a[i];
	bool cmp = true;
	for (int k = 1;k <= n;k++) {
		if (cmp && k != 1) {
			int sum = 1;
			for (int i = k - 1;i <= m;i++) {
				ans[i] += sum;
			}
			break;
		}
		int cnt = 0;
		for (int i = k;i <= n;i++) {
			int ans = -1;
			for (int j = 1;j <= cnt;j++) {
				if (now[j] == a[i]) {
					ans = j; break;
				}
			}
			if (ans == -1) {
				now[cnt + 1] = a[i]; cnt++; 
			} else {
				cnt = ans; now[cnt] = a[i]; cmp = false;
			}
		}
		for (int i = 1;i <= cnt;i++) ans[now[i]]++;
	}
	for (int i = 1;i <= m;i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}
