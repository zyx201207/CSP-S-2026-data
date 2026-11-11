#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int c,n,m,d,q;
ll w[500011];
ll f[511][511];
vector <pair<int,ll>> sta[500011];

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
		cin >> w[i];
	for(int i=1;i<=n;i++) {
		int k;
		cin >> k;
		for(int j=1;j<=k;j++) {
			int a; ll t;
			cin >> a >> t;
			sta[a].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)
		f[i][i] = 0;
	for(int i=1;i<=m;i++) {
		for(auto x : sta[i]) {
			for(auto y : sta[i]) {
				if (x.first == y.first)
					continue;
				int u = x.first,v = y.first;
				ll wu = x.second,wv = y.second;
				f[u][v] = min(f[u][v],wu + wv);
			}
		}
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			if (k == i)
				continue;
			for(int j=1;j<=n;j++) {
				if (k == j || i == j)
					continue;
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
	while (q--) {
		int u,v;ll ans;
		cin >> u >> v;
		ans = 0x3f3f3f3f3f3f3f3fll;
		for(auto x : sta[u]) {
			for(auto y : sta[v]) {
				int lx = x.first,ly = y.first;
				ans = min(ans,f[lx][ly] + x.second + y.second);
			}
		}
		cout << ans + w[u] + w[v] << '\n';
	}
	return 0;
}
