#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[200005], viss[200005], vis[40][100005], cur[40], lg[40], idx, ans;
void dl(int i) {
	int x = a[i];
	for (int j = 30; j >= 0 && x; j--)
		if (x >= lg[j]) {
			x -= lg[j];
			cur[j]--;
		}
}
void f(int x) {
	ans += lg[x];
	for (int i = 1; i <= n; i++)
		if (viss[i] && !vis[x][i])
			viss[i] = 0, dl(i);
	for (int i = x - 1; i >= 0; i--)
		if (cur[i] >= m) {
			f(i);
			break;
		}
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	lg[0] = 1;
	for (int i = 1; i <= 30; i++)
		lg[i] = lg[i - 1] * 2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		viss[i] = 1;
		cin >> a[i];
		int x = a[i];
		for (int j = 30; j >= 0 && x; j--)
			if (x >= lg[j]) {
				x -= lg[j];
				cur[j]++;
				vis[j][i] = 1;
			}
	}
	for (int i = 30; i >= 0; i--)
		if (cur[i] >= m) {
			idx = i;
			break;
		}
	ans += lg[idx];
	for (int i = 1; i <= n; i++)
		if (viss[i] && !vis[idx][i])
			viss[i] = 0, dl(i);
	for (int i = idx - 1; i >= 0; i--)
		if (cur[i] >= m) {
			f(i);
			break;
		}
	cout << ans;
	return 0;
}
