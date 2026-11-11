#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;
int mian(); int main() { return mian(); }

#define ll long long
#define fi first
#define se second
#define ppt pair<int, int>
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define pb push_back

#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define gch ch = getchar()
void read(int & x) { x = 0; char gch; while(!isdigit(ch)) gch; while(isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), gch; }
int stk_write[40], top_write;
void write(ll x) {
	if(!x) return putchar('0'), void();
	if(x < 0) putchar('-'), x = -x;
	while(x) stk_write[++top_write] = x % 10, x /= 10;
	while(top_write) putchar('0' + stk_write[top_write]), top_write--;
}
const int N = 5e5 + 55;
int Case, n, m, d, Q, _;
int w[N];

int f_edge[N], cnt_edge;
struct edge { int v, w, net; } eg[N << 1];
void addin(const int u, const int v, const int w) { eg[++cnt_edge] = (edge) { v, w, f_edge[u] }; f_edge[u] = cnt_edge; }

const int FN = 505;
ppt tim[N];
int tot;

void Min(ll & A, const ll B) { if(A > B) A = B; }
ll dis[FN][FN];
void get_dis() {
	FOR(i, 1, n) FOR(j, 1, n) dis[i][j] = 1e18;
	FOR(i, 1, n) dis[i][i] = 0;
	FOR(u, 1, m) {
		tot = 0; for(int i = f_edge[u]; i; i = eg[i].net) tim[++tot] = {eg[i].v, eg[i].w};
		FOR(i, 1, tot) FOR(j, i + 1, tot) {
			Min(dis[ tim[i].fi ][ tim[j].fi ], tim[i].se + tim[j].se);
			Min(dis[ tim[j].fi ][ tim[i].fi ], tim[i].se + tim[j].se);
		}
	}
	FOR(k, 1, n) FOR(i, 1, n) if(dis[i][k] < 1e18) FOR(j, 1, n) Min(dis[i][j], dis[i][k] + dis[k][j]);
}

int mian() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	_ = scanf("%d%d%d%d%d", &Case, &n, &m, &d, &Q);
	FOR(i, 1, m) read(w[i]);
	FOR(i, 1, n) {
		int k; read(k);
		FOR(p, 1, k) {
			int a, t; read(a), read(t);
			addin(a, i, t);
		}
	}
	get_dis();
	while(Q--) {
		int u, v; read(u); read(v);
		ll ans = 1e18;
		for(int i = f_edge[u]; i; i = eg[i].net) {
			for(int j = f_edge[v]; j; j = eg[j].net) {
				// cout<<eg[i].v<<" "<<eg[j].v<<"  "<<dis[eg[i].v][eg[j].v]<<" "<<eg[i].w<<" "<<eg[j].w<<endl;
				Min(ans, dis[ eg[i].v ][ eg[j].v ] + eg[i].w + eg[j].w);
			}
		}
		ans += w[u] + w[v];
		write(ans); putchar('\n');
	}
	return 0;
}