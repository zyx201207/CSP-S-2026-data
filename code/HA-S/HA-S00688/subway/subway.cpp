#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define sizf(x) ((int)(x).size())
#define report(...) fprintf(stderr, __VA_ARGS__)

inline ll read(void) {
	ll x=0,f=1; int ch;
	while (!isdigit(ch=getchar())) if (ch=='-') f=-1;
	for (;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	return x*f;
}

bool Mst;

const int M = 5e5+5, N = 505;
const ll inf = 1e18;
int cid, n, m, d, q;
int w[M];

vector<pair<int, ll> > E[M];

ll dis[N][N];

bool Med;

int main(void)
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cid = read(); n = read(); m = read(); d = read(); q = read();
	
	for (int i = 1; i <= m; i++) w[i] = read();
	for (int i = 1; i <= n; i++) {
		int k = read();
		while (k--) {
			int a = read(); int t = read();
			E[a].emplace_back(i, t);
		}
	}
	
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[i][j] = i == j ? 0 : inf;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < sizf(E[i]); j++) {
			for (int k = j + 1; k < sizf(E[i]); k++) {
				int u = E[i][j].fi, v = E[i][k].fi;
				dis[u][v] = dis[v][u] = min(dis[u][v], E[i][j].se + E[i][k].se);
			}
		}
	}
	
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				
	while (q--) {
		int u = read(); int v = read();
		
		ll ans = inf;
		for (auto x : E[u]) {
			for (auto y : E[v]) {
				ans = min(ans, dis[x.fi][y.fi] + x.se + y.se);
			}
		}
		printf("%lld\n", ans + w[u] + w[v]);
	}
	
	report("Mem : %lf MB\n", abs(&Med - &Mst) / 1024.0 / 1024.0);
	report("Time: %lf s\n", 1.0 * clock() / CLOCKS_PER_SEC);
	return 0;
}
