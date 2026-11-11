#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, m, a[5 * N + 3], stk[5 * N + 3], head = 0, cnt[3 * N + 3];
bool vis[3 * N + 3];
int main () {
	 freopen ("card.in", "r", stdin);
	 freopen ("card.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);cout.tie (0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) {
		head = 0;
		memset (vis, 0, sizeof (vis));
		for (int j = i; j <= n; j ++) {
			if (vis[a[j]]) {
				while (head >= 0) {
					if (stk[head] == a[j]) {
						head --;
						break;
					}
					vis[stk[head]] = 0; 
					head --;
				} 
				stk[++ head] = a[j];
			}
			else {
				stk[++ head] = a[j];
				vis[a[j]] = 1;
			}
		}
		for (int j = 1; j <= head; j ++) {
			cnt[stk[j]] ++;
		}
	}
	for (int i = 1; i <= m; i ++) cout << cnt[i] << ' ';
	return 0;
}

