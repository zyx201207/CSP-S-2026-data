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

#define file_name "subway"

const int N = 5e5 + 5;
const int M = 505;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int n, m;
int d, q;

#define fi first
#define se second
vector<pair<int, ll>> line[N];

ll dis[M][M];

int deg[N];
ll w[N];
void add(int u, int v, ll w){
	dis[u][v] = min(dis[u][v], w);
	dis[v][u] = min(dis[v][u], w);
}

void Solve(){
	m = read(), n = read(), d = read(), q = read();
	
	rep(i, 1, n) w[i] = read();
	rep(i, 1, m){
		int k = read();
		rep(j, 1, k){
			int a = read(); ll t = read();
			line[a].push_back({i, t});
			deg[a]++;
		}
	}
	
	memset(dis, 0x3f, sizeof(dis));
	
	rep(i, 1, m) dis[i][i] = 0;
	rep(u, 1, n){
//		fpf("u: %d, deg[u]: %d\n", u, deg[u]);
//		rep(i, 0, deg[u] - 1) fpf("(%d, %lld) ", line[u][i].fi, line[u][i].se);
//		fpf("\n");
		rep(i, 0, deg[u] - 1){
			rep(j, i + 1, deg[u] - 1){
				pair<int, ll> li = line[u][i], lj = line[u][j];
				add(li.fi, lj.fi, li.se + lj.se);
			}
		}
	}
	
	rep(k, 1, m){
		rep(i, 1, m){
			if(i == k || dis[i][k] >= inf) continue;
			rep(j, 1, m){
				if(j == k || dis[k][j] >= inf) continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	
	while(q--){
		int u = read(), v = read();
		ll ans = inf;
		rep(i, 0, deg[u] - 1){
			rep(j, 0, deg[v] - 1){
				pair<int, ll> li = line[u][i], lj = line[v][j];
				ans = min(ans, dis[li.fi][lj.fi] + li.se + lj.se);
			}
		}
		ans += w[u] + w[v];
		write(ans);
	}
	
//	fpf("used time = %.3lf ms\n", 1. * clock() / CLOCKS_PER_SEC * 1000);
}

#undef fi
#undef se
signed main(){
	#ifdef lajishift
//		freopen("subway7.in", "r", stdin);
//		freopen("my.out", "w", stdout);
	#elif defined(file_name)
		freopen(file_name ".in", "r", stdin);
		freopen(file_name ".out", "w", stdout);
	#endif

	T = 1, C = read();
	while(T--) Solve();
	return 0;
}

