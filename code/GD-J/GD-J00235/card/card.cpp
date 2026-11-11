#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],vis[500005],ans[500005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) {
		int cnt = 0;
		memset(vis,-1,sizeof vis);
		for (int j = i;j <= n;j++) {
			if (vis[a[j]] == -1) {
				b[++cnt] = a[j];
				vis[a[j]] = cnt;
			} else {
				int nc = vis[a[j]] - 1;
				for (int k = vis[a[j]];k <= cnt;k++) {
					vis[b[k]] = -1;
					b[k] = 0;
				}
				cnt = nc;
				b[++cnt] = a[j];
				vis[a[j]] = cnt;
			}
		}
		for (int j = 1;j <= cnt;j++) {
			ans[b[j]]++;
		}
	}
	for (int i = 1;i <= m;i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
