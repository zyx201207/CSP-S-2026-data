#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define eb emplace_back
#define PII pair<int, int>
#define mse(x, y) memset(x, y, sizeof(x))
#define mcp(x, y) memcpy(x, y, sizeof(x))
#define rep(x, l, r) for(int x = l; x <= r; x++)
#define drep(x, r, l) for(int x = r; x >= l; x--)
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXM = 5e5 + 5, MAXN = 505;
int c, n, m, d, q, w[MAXM], dis[MAXN][MAXN], _G[MAXN][MAXN];
bool vis[MAXN];
vector<PII > G[MAXM], __G[MAXN];//i : µÚi¸öµØÌúÕ¾Ìü
priority_queue<PII> Q;

void dij(int s){
	while(Q.size()) Q.pop();
	mse(dis[s], 0x3f), mse(vis, 0);
	dis[s][s] = 0;
	Q.push( {0, s} );
	while(Q.size()){
		int u = Q.top().se; Q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto e : __G[u]){
			int w = e.se, v = e.fi;
			if(dis[s][v] > dis[s][u] + w) dis[s][v] = dis[s][u] + w, Q.push( {-dis[s][v], v} );
		}
	}
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	FASTIO;
	cin >> c >> n >> m >> d >> q;
	rep(i, 1, m) cin >> w[i];
	rep(i, 1, n){
		int k;
		cin >> k;
		rep(j, 1, k){
			int u, w;
			cin >> u >> w, G[u].pb( {i, w} ); 
		}
	}
	mse(_G, 0x3f);
	rep(i, 1, n) _G[i][i] = 0;
	rep(i, 1, m) rep(j, 0, ((int)G[i].size()) - 1) rep(k, j + 1, ((int)G[i].size()) - 1){
		int u = G[i][j].fi, v = G[i][k].fi, w = G[i][j].se + G[i][k].se;
		_G[u][v] = _G[v][u] = min(_G[v][u], w);
	}
	rep(i, 1, n) rep(j, 1, n) if(_G[i][j] != 0x3f3f3f3f3f3f3f3f) __G[i].pb( {j, _G[i][j]} );
	rep(i, 1, n) dij(i);
	rep(i, 1, q){
		int x, y, ans = 0x3f3f3f3f3f3f3f3f;
		cin >> x >> y;
		for(auto U : G[x]){
			for(auto V : G[y]){
				int u = U.fi, v = V.fi;
				ans = min(ans, U.se + V.se + w[x] + w[y] + dis[u][v]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
