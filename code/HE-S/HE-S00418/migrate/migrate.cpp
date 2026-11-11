#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

int n, d, res = 0, minn = INF;
int a[N];
//int f[i][j], cnt[i][j];
bool st[N];

void dfs(int u, int v, int cnt, int now) {
	if (cnt > minn) return;
	if (now == v) {
		if (cnt == minn) res++;
		else if (cnt < minn) minn = cnt, res = 1;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!st[i] && abs(a[i] - a[now]) <= d) {
			st[i] = true;
			dfs(u, v, cnt + 1, i);
			st[i] = false;
		}
	}
	return;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (n <= 9) {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					res = 0, minn = INF;
					st[i] = true;
					dfs(i, j, 0, i);
					st[i] = false;
					if (res == 2)
						ans++;
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
//		} else if (n <= 300) {
//			for (int k = 1; k <= n; k++)
//				for (int i = 1; i <= n; i++)
//					for (int j = 1; j <= n; j++)
//						f[i][j] = INF;
//			for (int k = 1; k <= n; k++) f[k][k] = 0;
//			for (int i = 1; i <= n; i++)
//				for (int j = 1; j <= n && j != i; j++)
//					if (abs(a[i] - a[j]) <= d)
//						f[i][j] = 1;
//			for (int k = 1; k <= n; k++)
//				for (int i = 1; i <= n; i++)
//					for (int j = 1; j <= n; j++)
//						if (abs(a[i] - a[k]) <= d && abs(a[k] - a[j]) <= d)
//							f[i][j] = min(f[i][j], f[i][k] + f[k][j]); 
//			
//		} else {
//			
//		}
} 
 
