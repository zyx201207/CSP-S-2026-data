#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int c, n, m, d, q, w[500005], k[505], a[505][400001], t[505][400005], u[505][505], book[500005], x, y;
ll len, ans;

void dfs(int p, int l) {
	if (len >= ans) return;
	if (p==y) {
		ans = min(ans, len+t[l][y]);
		return;
	}
	for (int i=1; i<=m; i++) {
		if (book[i]) continue;
		if (u[p][i]>0 && u[p][i]!=l) {
			len += t[l][p]+t[u[p][i]][p];
			book[i]=1;
			dfs(i, u[p][i]);
			len -= t[l][p]+t[u[p][i]][p];
			book[i]=0;
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i=1; i<=m; i++) {
		cin >> w[i];
	}
	for (int i=1; i<=n; i++) {
		cin >> k[i];
		for (int j=1; j<=k[i]; j++) {
			cin >> a[i][j];
			cin >> t[i][a[i][j]];
		}
		for (int j=1; j<=k[i]-1; j++) {
			for (int l=j+1; l<=k[i]; l++) {
				u[a[i][j]][a[i][l]] = i;
				u[a[i][l]][a[i][j]] = i;
			}
		}
	}
	for (int _=1; _<=q; _++) {
		cin >> x >> y;
		book[x] = 1;
		ans = 1e18;
		len = 0;
		
		for (int i=1; i<=m; i++) {
		    if (book[i]) continue;
		    if (u[x][i]>0) {
		    	len += t[u[x][i]][x];
		    	book[i] = 1;
		    	dfs(i, u[x][i]);
		    	len -= t[u[x][i]][x];
		    	book[i] = 0;
			}
		}
		
		cout << ans+w[x]+w[y] << '\n';
	}
	
	return 0;
}

