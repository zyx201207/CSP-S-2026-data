#include<bits/stdc++.h>
using namespace std;
const int N=500050, M=505;
const long long inf=1e14;
int n, m, i, j, k, d, q, x, y, a[N];
vector<pair<int, int> > z[N]; 
long long f[M][M], ans;
void in(int &k) {
	char c = getchar();
	int s = 0;
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') s = (s<<1)+(s<<3)+c-48, c = getchar();
	k = s;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	in(n), in(n), in(m), in(d), in(q);
	for (i=0; i<M; i++) {
		for (j=0; j<M; j++) f[i][j] = inf;
	}
	for (i=1; i<=m; i++) in(a[i]);
	for (i=1; i<=n; i++) {
		in(k);
		for (j=1; j<=k; j++) {
			in(x), in(y);
			for (auto s : z[x]) f[s.first][i] = min(f[s.first][i], 1ll*y+s.second);
			z[x].push_back({i, y}); 
		}
	}
	for (i=1; i<=n; i++) f[i][i] = 0;
	for (i=1; i<=n; i++) {
		for (j=1; j<=n; j++) f[i][j] = min(f[i][j], f[j][i]);
	}
	for (k=1; k<=n; k++) {
		for (i=1; i<=n; i++) {
			for (j=1; j<=n; j++) f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
		}
	}
	for (i=1; i<=q; i++) {
		scanf("%d%d", &x, &y);
		ans = inf;
		for (auto j : z[x]) {
			for (auto k : z[y]) {
				ans = min(ans, j.second+k.second+f[j.first][k.first]);
			}
		}
		printf("%lld\n", ans+a[x]+a[y]);
	}
	return 0;
}

