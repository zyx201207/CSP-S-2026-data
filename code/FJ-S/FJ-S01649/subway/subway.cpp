#include<bits/stdc++.h>
using namespace std;
using LL = long long;

LL read() {
	LL x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch=='-'), ch = getchar();
	while(isdigit(ch)) x = (x<<3)+(x<<1)+(ch^48), ch = getchar();
	return f ? -x : x;
}

const int N = 505, M = 5e5+5;
const LL inf = 0x3f3f3f3f3f3f3f3f;
int c;
int n, m, d, q;
LL w[M], dis[N][N];
vector<int> a[N], id[M];
vector<LL> t[N], idt[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	c = read(), n = read(), m = read(), d = read(), q = read();
	for(int i = 1; i <= m; i++) w[i] = read();

	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= n; i++) {
		dis[i][i] = 0;
		int k = read();
		a[i].resize(k+1); t[i].resize(k+1);
		for(int j = 1; j <= k; j++) {
			a[i][j] = read(), t[i][j] = read();
			id[a[i][j]].push_back(i); idt[a[i][j]].push_back(t[i][j]);
		}
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 0; j < id[i].size(); j++)
			for(int k = j+1; k < id[i].size(); k++) {
				int u = id[i][j], v = id[i][k]; LL wt = idt[i][j]+idt[i][k];
				dis[u][v] = min(dis[u][v], wt); dis[v][u] = min(dis[v][u], wt);
			}
	}

	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
	
	while(q--) {
		int x = read(), y = read();
		LL ans = inf;
		for(int i = 0; i < id[x].size(); i++)
			for(int j = 0; j < id[y].size(); j++) {
				int u = id[x][i], v = id[y][j];
				ans = min(ans, idt[x][i]+idt[y][j]+dis[u][v]);
			}
		printf("%lld\n", ans+w[x]+w[y]);
	}

	return 0;
}