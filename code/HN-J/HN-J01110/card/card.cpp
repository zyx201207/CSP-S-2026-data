#include <iostream>
#include <cstring>
using namespace std;

int n, m, a[500005], stack[300300], vis[300003], ans[300003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 1, t = 0; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		for (int j = i; j <= n; j++) {
			if (vis[a[j]]) {
				while (stack[t] != a[j]) vis[stack[t--]]--;
				vis[stack[t--]]--;
			}
			vis[stack[++t] = a[j]]++;
		}
		for (int j = 1; j <= m; j++) ans[j] += vis[j] != 0;
	}
	
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}

