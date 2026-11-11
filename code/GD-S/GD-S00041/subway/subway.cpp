#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
const int INF = 0x3f3f3f3f;
const int M = 5e5 + 10, N = 505;
int w[M], arr[M];
bool vis[M][N];
bool nw[M];
int t[M][N];
int c, n, m, d, q;
vector<PII> g[M];
void add(int a, int b, int c) {
	g[a].push_back({b, c});
}
int st, en, ans = INF;
void dfs(int u, int fa, int ux, int sum) {
	int res = INF;
	if(u == en) {
		ans = min(ans, sum + t[u][ux]);
		return;
	}
	for(auto e : g[u]) {
		int ns = sum;
		int v = e.first, vx = e.second;
		if(v == fa && nw[v] == 1) continue;
//		printf("u:%d, ux:%d, v:%d, vx:%d\n", u, ux, v, vx);
		if(ux != vx) {
			ns += (t[u][ux] + t[u][vx]); 
		}
		nw[v] = 1;
		dfs(v, u, vx, ns);
		nw[v] = 0;
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	cin >> c >> n >> m >> d >> q;
	rep(i, 1, m) {
		cin >> w[i];
	}
	rep(i, 1, n) {
		int k;
		cin >> k;
		rep(j, 1, k) {
			int a, tt;
			cin >> a >> tt;
			arr[j] = a;
			t[a][i] = tt;
			vis[a][i] = 1;
			if(j >= 2) {
				int b = arr[j - 1];
				add(a, b, i);
				add(b, a, i);
			}
		}
	}
	rep(i, 1, q) {
		cin >> st >> en;
		int fan = INF;
		rep(j, 1, n) {
			nw[st] = 1;
			dfs(st, 0, j, w[st] + w[en] + t[st][j]);
			nw[st] = 0;
			if(vis[st][j]) fan = min(fan, ans);
		}
		cout << fan << endl;
	}
	return 0;
}

