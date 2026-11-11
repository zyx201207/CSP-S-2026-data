#include<bits/stdc++.h>
using namespace std;
const int M = 405;
const int N = 205;
int k[N], w[M], a[N][M], t[N][M], c, n, m, d, q, x, y, rk[M][N];
vector<int> line[M];
long long dis[M];
bool vis[M][N];

inline void dfs(int x) {
	for(auto l:line[x]) {
		if(vis[x][l]) continue;
		vis[x][l] = 1;
		for(int i=1;i<=k[l];i++) {
			if(a[l][i] == x) continue;
			dis[a[l][i]] = min(dis[a[l][i]], dis[x] + t[l][rk[x][l]] + t[l][i]);
			dfs(a[l][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		for(int j=1;j<=k[i];j++) {
			cin>>a[i][j]>>t[i][j];
			line[a[i][j]].push_back(i);
			rk[a[i][j]][i] = j;
		}
	}
	while(q--) {
		cin>>x>>y;
		memset(vis, 0 ,sizeof vis);
		for(int i=1;i<=m;i++) {
			dis[i] = 5e15;
		}
		dis[x] = 0;
		dfs(x);
		cout<<w[x] + dis[y] + w[y]<<"\n";
	}
	return 0;
}
