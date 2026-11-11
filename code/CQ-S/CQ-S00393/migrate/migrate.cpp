#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t, ct = 0;
int n, d, cnt = 0, res = 0, minn = 1000000;
int a[200005];
int vis[200005];
int siz[200005];
void dfs(int st, int fi, int cs) {
	if(st == fi) {
		minn = min(minn, cs);
		siz[++ct] = cs;
		return ;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		vis[i] = 1;
		if(a[i] - a[st] > 0 && a[i] - a[st] <= d) {
			dfs(i, fi, cs+1);
		}
		vis[i] = 0;
	}
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if(c == 1 || c == 2) {
		while(t--) {
			cin >> n >> d;
			for(int i = 1; i <= n; i++) {
				cin >> a[i];
			}
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					cnt = 0, ct = 0, minn = 100000;
					memset(vis, 0, sizeof vis);
					dfs(i, j, 0);
					for(int i = 1; i <= ct; i++) {
						if(siz[i] == minn) {
							cnt++;
						}
					}
					if(cnt == 2) res++;
				}
			}
			cout << res << endl;
		}
	}
	return 0;
}

