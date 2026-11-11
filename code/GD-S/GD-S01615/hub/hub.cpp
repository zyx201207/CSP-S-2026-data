#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define per(i, r, l) for(int i = r; i >= l; i--)
typedef long long ll;
ll read(){
	ll res = 0, flg = 1; char c = getchar();
	for(; c > '9' || c < '0'; c = getchar()) if(c == '-') flg = -flg;
	for(; c >= '0' && c <= '9'; c = getchar()) res = (res << 3) + (res << 1) + c - '0';
	return res * flg;
}
void write(ll x, char c = '\n'){
	if(x < 0){ putchar('-'); x = -x; }
	static int stk[40], top = 0;
	do { stk[++top] = x % 10; x /= 10; } while(x);
	while(top){ putchar('0' + stk[top--]); }
	putchar(c);
}
#define fpf(...) fprintf(stderr, __VA_ARGS__)
#define prt(...) fprintf(stdout, __VA_ARGS__)
int T, C;

#define file_name "hub"

const int N = 1e6 + 5;

int n, k;
vector<int> tr[N];
vector<pair<int, int>> edges;

struct Info{
	int len;
	int u, v;
} mx[2];

bool ban[N];

#define fi first
#define se second
pair<int, int> f[N];

void dfs(int u, int fa, int idx){
	f[u] = {0, u};
	for(int v : tr[u]){
		if(v == fa || (ban[u] && ban[v])) continue;
		dfs(v, u, idx);
		if(f[u].fi + f[v].fi + 1 > mx[idx].len){
			mx[idx].len = f[u].fi + f[v].fi + 1;
			mx[idx].u = f[u].se, mx[idx].v = f[v].se;
		} 
		f[u] = max(f[u], make_pair(f[v].fi + 1, f[v].se));
	}
}

int stk[2][N], top[2];
bool flg[2];
void dfs2(int u, int fa, int to, int idx){
	stk[idx][++top[idx]] = u;
	if(u == to || flg[idx]){
		flg[idx] = 1;
		return;
	}
	for(int v : tr[u]){
		if(v == fa || (ban[u] && ban[v])) continue;
		dfs2(v, u, to, idx);
		if(flg[idx] == 1) return;
	}
	top[idx]--;
}


int ans;

bool vis[N];
int mid[2][2];
int fa[N];
vector<int> leaf[2];
int dep[N];
void dfs3(int u, int idx){
	vis[u] = 0;
	int cnt = 0;
	for(int v : tr[u]){
		if(v == fa[u] || (ban[u] && ban[v])) continue;
		cnt++;
		fa[v] = u;
		dep[v] = dep[u] + 1;
		dfs3(v, idx);
	}
	if(!cnt) leaf[idx].push_back(u);
}

int calc(int rt, int idx, int d){
//	fpf("rt: %d, idx: %d, d: %d\n", rt, idx, d);
	fa[rt] = dep[rt] = 0;
	dfs3(rt, idx);
	int res = 0;
	sort(leaf[idx].begin(), leaf[idx].end(), [](int u, int v){ return dep[u] > dep[v]; });
//	fpf("leaf: ");
//	for(int u : leaf[idx]) fpf("%d ", u);
//	fpf("\n");
	for(int u : leaf[idx]){
		if(dep[u] <= d || vis[u] || u == rt) continue;
//		fpf("=====================================================  %d\n", u);
		vis[u] = 1;
		if(d == 0) res++;
		int step = 1, t = fa[u];
		while(t != rt){
			if(vis[t]) break;
			vis[t] = 1;
//			fpf("t: %d, step: %d\n", t, step);
			if(step >= d){
				res++;
			}
			t = fa[t];
			step++;
		}
	}
	leaf[idx].clear();
	return res + 1;
}
bool check(int d){
	int res0 = calc(mid[0][0], 0, d);
	if(mid[0][1] > 0) res0 = min(res0, calc(mid[0][1], 0, d));
	int res1 = calc(mid[1][0], 1, d);
	if(mid[1][1] > 0) res1 = min(res1, calc(mid[1][1], 1, d));
//	fpf("check: d: %d, res0: %d, res1: %d\n", d, res0, res1);
	return res0 + res1 <= k;
}
int calc(int u, int v){
//	fpf("u: %d, v: %d           ===========================================================\n", u, v);
	ban[u] = ban[v] = 1;
	mx[0] = {0, u, u}, mx[1] = {0, v, v};
	dfs(u, v, 0), dfs(v, u, 1);
	top[0] = top[1] = 0;
	flg[0] = flg[1] = 0;
	dfs2(mx[0].u, 0, mx[0].v, 0), dfs2(mx[1].u, 0, mx[1].v, 1);
	rep(i, 0, 1){
		mid[i][0] = mid[i][1] = 0;
		if(top[i] & 1) mid[i][0] = stk[i][(top[i] + 1) / 2];
		else mid[i][0] = stk[i][top[i] / 2], mid[i][1] = stk[i][top[i] / 2 + 1];
	}
//	fpf("mx[0].len: %d, mx[0].u: %d mx[0].v: %d\n", mx[0].len, mx[0].u, mx[0].v);
//	fpf("top[0]: %d\n", top[0]);
//	fpf("mid[0][0]: %d, mid[0][1]: %d\n", mid[0][0], mid[0][1]);
//	fpf("mx[1].len: %d, mx[1].u: %d mx[1].v: %d\n", mx[1].len, mx[1].u, mx[1].v);
//	fpf("top[1]: %d\n", top[1]);
//	fpf("mid[1][0]: %d, mid[1][1]: %d\n", mid[1][0], mid[1][1]);
	int l = 0, r = n - 1, res = n - 1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			r = mid - 1;
			res = mid;
		}else{
			l = mid + 1;
		}
	}
	
	ban[u] = ban[v] = 0;
	
//	fpf("res: %d\n", res);
	return res;
}

void Solve(){
	n = read(), k = read();
	rep(i, 1, n - 1){
		int u = read(), v = read();
		tr[u].push_back(v);
		tr[v].push_back(u);
		edges.push_back({u, v});
	}
	
	ans = n - 1;
	for(pair<int, int> e : edges){
		int u = e.first, v = e.second;
		ans = min(ans, calc(v, u));
	}
	write(ans);
	
	edges.clear();
	rep(u, 1, n) tr[u].clear();
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 2
5 2
1 2
1 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 1
18 2
1 2
2 3
3 4
3 5
2 7
7 6
7 8
1 10
10 9
10 11
10 12
12 13
12 18
18 15
18 14
11 17
11 16
*/
signed main(){
	#ifdef lajishift
//		freopen("hub3.in", "r", stdin);
	#elif defined(file_name)
		freopen(file_name ".in", "r", stdin);
		freopen(file_name ".out", "w", stdout);
	#endif

	C = read(), T = read();
	while(T--) Solve();
	return 0;
}

