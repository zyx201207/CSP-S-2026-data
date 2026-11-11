#include <bits/stdc++.h>
using namespace std;
#define deb(n) cout << #n << " = " << n << '\n';
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int a[N];
int now[M];
int cnt[M];
bool vis[M];
int n, m;
int idx = 0;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	bool flag = true;
	for (int i = 1; i <= n - 1; i++) {
		if (a[i] > a[i + 1]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		for (int i = 1; i <= m; i++) cout << n << ' ';
	}
	for (int s = 1; s <= n; s++) { // 每局游戏
		idx = 0;
		for (int i = s; i <= n; i++) { // 插入每个元素
			for (int j = 1; j <= idx; j++) {
				if (now[j] == a[i]) {
					for (int k = j; k <= idx; k++) now[k] = 0;
					idx = j - 1;
					break;
				}
			}
			now[++idx] = a[i];
//			deb(a[i]);
//			for (int j = 1; j <= idx; j++) cout << now[j] << ' ';

		}
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= idx; i++) {
			if (vis[now[i]]) continue;
			cnt[now[i]] ++;
			vis[now[i]] = true;
		}

//		for (int i = 1; i <= m; i++) cout << cnt[i] << ' ';
//		cout << '\n';
	}
	for (int i = 1; i <= m; i++) cout << cnt[i] << ' ';
	return 0;
}
