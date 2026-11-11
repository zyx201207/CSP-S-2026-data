#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fs first
#define sc second
const int maxn = 5e5 + 1, maxk = 30, inf = INT_MAX; 
inline int read(){
	int x = 0,f = 1; char c = getchar();
	while(c < '0' || c > '9')  {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c - '0');
		c = getchar();
	}
	return x * f;
}
int cnt = 0, c, n, m, d, q;
vector < pair<int,int> > g[maxn << 1];
vector <int> a[maxn], t[maxn];
int id[maxn][maxk], _w[maxn][maxk];
pair<int, pair<int,int> > zt[1 << 21]; // id[i][j] : 第 i 个地铁站到第 l[i][j] 条线路的编号 // j = 0 时 为站厅 
vector <int> l[maxn];
int dis[1 << 21];
int dijk(int s, int t){
	for(int i = 1;i <= cnt;i++) dis[i] = inf;
	dis[s] = 0; priority_queue < pair<int,int> > _q;
	_q.push({0, s});
	while(!_q.empty()) {
		pair<int,int> _x = _q.top(); _q.pop();
		int _w = _x.fs, _u = _x.sc;
		if(dis[_u] < _w) continue;
		for(pair<int,int> _p : g[_u]) {
			int _v = _p.fs, _z = _p.sc;
			if(dis[_v] > dis[_u] + _z) {
				dis[_v] = dis[_u] + _z;
				_q.push({dis[_v], _v});
			}
		}
	}
	return dis[t];
} 
void solve() {
	c = read(), n = read(), m = read(), d = read(), q = read();
	vector <int> w(m + 10), k(n + 10);
	for(int i = 1;i <= m;i++) w[i] = read(), id[i][0] = ++cnt, l[i].push_back(0); 
	for(int i = 1;i <= n;i++) {
		k[i] = read(); a[i].resize(k[i] + 1);
		t[i].resize(k[i] + 1);
		for(int j = 1;j <= k[i];j++){
			a[i][j] = read(), t[i][j] = read();
			l[a[i][j]].push_back(i);
			id[a[i][j]][l[a[i][j]].size() - 1] = ++cnt;
			zt[cnt] = {i, {j, l[a[i][j]].size() - 1}};
			_w[a[i][j]][l[a[i][j]].size() - 1] = t[i][j];
		}	
	}
	for(int i = 1;i <= m;i++)
		for(int j = 1;j < l[i].size();j++){
			g[id[i][0]].push_back({id[i][j], _w[i][j]});
			g[id[i][j]].push_back({id[i][0], _w[i][j]});
//			cout << id[i][0] << " " << id[i][j] << " " << _w[i][j] << "\n";
		}
	for(int i = m + 1;i <= cnt;i++) {
		int x = zt[i].fs, y = zt[i].sc.fs, k = zt[i].sc.sc;
		if(y == 1) continue;
		else {
			g[id[a[x][y]][k]].push_back({id[a[x][y]][k] - 1, 0});
			g[id[a[x][y]][k] - 1].push_back({id[a[x][y]][k], 0});
//			cout << id[a[x][y]][k] << " " << id[a[x][y]][k] - 1 << "\n";
		}
	}
	for(int i = 1;i <= q;i++) {
		int xr = read(), yr = read();
		int ans = w[xr] + w[yr] + dijk(xr, yr);
		cout << ans << "\n"; 
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int t = 1;
	while(t--) solve();
}

