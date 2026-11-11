#include <bits/stdc++.h>

using namespace std;

long long c, n, m, d, q;
long long w[25005];
long long a[505][25005], t[505][25005], vis[25005];
long long ans;

//long long box[25005], cnt = 0;

void dfs(int u, int v, int k, long long sum) {
	if (k == v) {
		ans = min(ans, sum);
//		for (int i = 1; i <= cnt; i++) {
//			cout << box[i] << ' ';
//		}
//		cout << sum << endl;
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		bool f = false;
		int idx = 0;
		for (int j = 1; j <= a[i][0]; j++) {
			if (a[i][j] == k) {
				idx = j;
				f = true;
				break;
			}
		}
		if (f) {
			for (int j = 1; j <= a[i][0]; j++) {
				if (a[i][j] == k) continue;
				if (vis[a[i][j]] == 0) {
					vis[a[i][j]] = 1;
//					box[++cnt] = a[i][j];
					dfs(u, v, a[i][j], sum + t[i][idx] + t[i][j]);
					vis[a[i][j]] = 0;
//					cnt--;
				}
			}
		}
	} 
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		a[i][0] = k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		ans = LONG_LONG_MAX;
//		box[++cnt] = u;
		dfs(u, v, u, 0);
//		cnt--;
		cout << w[u] + w[v] + ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

