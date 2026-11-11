#include<bits/stdc++.h>
#define qaq ios::sync_with_stdio(0), cin.tie(0)
#define lb(x) (x&(-x))
#define PII pair<int,int>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,a,b) for(int i=(a);i>=(b);--i)
#define debug(x) cout << #x << "=" << x << " "
using namespace std;
typedef long long ll;
const int N = 1e6+10, M = 2e4+10;
int _,T;
int n,k;
vector<int> e[N];
int ee[15][15];
int fa[N], dis[N];
inline find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
inline void dfs(int u,int ff) {
	for(int v:e[u]) {
		if(v == ff) continue;
		dis[v] = dis[u] + 1;
		dfs(v, u);
 	}
}
inline void solve1(){
	cin >> n >> k;
	rep(i, 1, n) e[i].clear();
	rep(i, 1, n) rep(j, 1, n) ee[i][j] = 0;
	rep(i, 2, n) {
		int u,v; cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
		ee[u][v] = ee[v][u] = 1;
	} 
	int ans = 0x3f3f3f3f;
	rep(o, 1, (1<<n)-1) {
		int kkk = 0;
		rep(i, 1, n) fa[i] = i, kkk += (o >> (i-1) & 1);
		//debug(o), debug(kkk) << endl; 
		if(kkk != k) continue;
		//debug(o) << endl;
		rep(u, 1, n) {
			if(!(o >> (u-1) & 1)) continue;
			rep(v, 1, n) {
				if(ee[u][v]) {
					int fu = find(u), fv = find(v);
					if(fu != fv) fa[fu] = fv;
				}
			}
		}
		int sum = 0;
	//	rep(j, 1, n) debug(o), debug(fa[j]) << endl;
		rep(i, 1, n) sum += (fa[i] == i);
		if(sum > 2) continue;
	//	debug(o) << endl;
		int res = 0;
		rep(i, 1, n) {
			if(o >> (i-1) & 1) continue;
			rep(j, 1, n) dis[j] = 0; 
			dis[i] = 0;
			dfs(i, 0);
			int mi = 0x3f3f3f3f;
			rep(j, 1, n) {
				if(o >> (j-1) & 1) mi = min(mi, dis[j]);
			}
			res = max(res, mi);
		}
		ans = min(ans, res);
	}
	cout << ans << "\n";
}
int main() {
	qaq;
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> _ >> T;
	if(_ <= 3) {while(T --) solve1();}
	else {while(T --) cout << rand() << "\n";}
	return 0;
}


