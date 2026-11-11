#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, d, x[(int)1e6+5];
int ans = 0;
signed main() {
//	freopen("migrate4.in", "r", stdin);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, t;
	cin>>c>>t;
	while(t--) {
		ans = 0;
		cin>>n>>d;
		for (int i=1;i<=n;i++) {
			cin>>x[i];
		}
		for (int u=1;u<=n;u++) {
			for (int v=u+1;v<=n;v++) {
				if (x[v] - x[u] <= d) continue;
				int p=0;
				for (int i=u+1;i<v;i++) {
					if (x[i] - x[u] <= d && x[v] - x[i] <= d) p++;
				}
				if (p == 2) ans ++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
