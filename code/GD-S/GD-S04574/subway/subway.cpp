//cin is faster than fast read!?
#include <bits/stdc++.h>
using namespace std;

const int MXN = 500;
const int MXM = 5e5;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int c, n, m, d, q, w[MXM], k[MXN];
long long ns;
vector< int > a[MXN];
vector< int > t[MXN];
struct edge{
	int v, w;
};
vector< edge > g[MXM];
long long dst[MXN][MXN];

void Floyd(){
	int i, j, k;
	for(i = 0;i < n;++i)
		for(j = 0;j < n;++j)
			for(k = 0;k < n;++k) dst[j][k] = min(dst[j][k], dst[j][i] + dst[i][k]);
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	cin >> c >> n >> m >> d >> q;
	for(i = 0;i < m;++i) cin >> w[i];
	for(i = 0;i < n;++i){
		cin >> k[i];
		a[i].resize(k[i]);
		t[i].resize(k[i]);
		for(j = 0;j < k[i];++j){
			cin >> a[i][j] >> t[i][j];
			--a[i][j];
			g[a[i][j]].push_back({i, t[i][j]});
		}
	}
	for(i = 0;i < n;++i)
		for(j = 0;j < n;++j)
			if(i != j) dst[i][j] = INF;
	for(i = 0;i < n;++i)
		for(j = 0;j < k[i];++j)
			for(auto x : g[a[i][j]]){
				int v = x.v, w = x.w;
				dst[v][i] = dst[i][v] = min(dst[i][v], (long long)t[i][j] + w);
			}
	Floyd();
	for(;q;--q){
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		ns = INF;
		for(i = 0;i < (int)g[x].size();++i)
			for(j = 0;j < (int)g[y].size();++j) ns = min(ns, g[x][i].w + dst[g[x][i].v][g[y][j].v] + g[y][j].w);
		cout << w[x] + ns + w[y] << '\n';
	}
	return 0;
}
