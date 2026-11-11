#include<stdio.h>
#include<queue>

using pii = std::pair<int, int>;
using ll = long long;
constexpr ll N = 5e5 + 10, M = 510, INF = 9e18;
int c, n, m, d, q, Z[N]; ll dis[M][M];
int to[M][N];
std::vector<pii> g[N];
std::vector<int> col[N];
inline ll min(ll x, ll y){return x < y ? x : y;}

int p; char s;
inline int read(){
	p = 0; s = getchar();
	while(s < '0' || s > '9') s = getchar();
	while(s >= '0' && s <= '9') p = (p << 1) + (p << 3) + (s ^ 48), s = getchar();
	return p;
}

void cin(){
	freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
	int k, v, val;
	c = read(); m = read(); n = read(); d = read(); q = read();
	for(int i = 1; i <= m; i++) for(int j = 1; j <= m; j++) if(i != j) dis[i][j] = INF;
	for(int i = 1; i <= n; i++) Z[i] = read();
	for(int i = 1; i <= m; i++){
		k = read();
		while(k--){
			v = read(), val = read(); to[i][v] = val;
			for(pii t : g[v]) dis[t.first][i] = min(dis[t.first][i], t.second + val);
			g[v].push_back({i, val});
		}
	}
}

void sol(){
	int u, v; ll ans, sum;
	while(q--){
		u = read(); v = read(); sum = Z[u] + Z[v]; ans = 9e18;
		for(int i = 1; i <= m; i++) for(int j = 1; j <= m; j++) if(to[i][u] && to[j][v]) ans = min(ans,
		to[i][u] + dis[i][j] + to[j][v] + sum);
		printf("%lld\n", ans);
	}
}

int main(){cin(); sol();}
