#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, d, x[2000005], di[10005], cnt[10005];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin>>c>>t;
	c = 10;
	while (t--) {
		cin>>n>>d;
		for (int i = 1; i <= n; i++) cin>>x[i];
		if (c == 11 || c == 12) {
			int once = d / abs(x[2] - x[1]);
			if (once < 2) {
				cout<<"0\n";
				continue;
			}
			cout<<max(n-2*once+1, 0ll)<<'\n';
			continue;
		}
		if (c <= 10) {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				memset(di, 0x3f, sizeof(di));
				memset(cnt, 0, sizeof(cnt));
				queue<int> q;
				q.push(i);
				di[i] = 0;
				while (!q.empty()) {
					int u = q.front();
					q.pop();
					int* downptr = lower_bound(x+1, x+1+n, x[u]-d);
					if (*downptr != x[u] - d && downptr != x+1) downptr++;
					int down = downptr - x;
					int* upptr = upper_bound(x+1, x+1+n, x[u]+d);
					if (*upptr != x[u] + d && upptr != x+n+2) upptr--;
					int up = upptr - x;
//					cout<<u<<' '<<down<<' '<<up<<'\n';
					for (int j = down; j <= up; j++) {
						if (di[j] > di[u] + 1) {
							di[j] = di[u] + 1;
							cnt[j] = 1;
							q.push(j);
						} else if (di[j] == di[u] + 1) cnt[j]++;
					}
				}
//				for (int j = 1; j <= n; j++) cout<<(di[j]==0x3f3f3f3f3f3f3f3f?-1:di[j])<<' ';
				for (int j = i+1; j <= n; j++) ans += (cnt[j] == 2); // cout<<cnt[j]<<' ';
//				cout<<'\n';
			}
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
}
