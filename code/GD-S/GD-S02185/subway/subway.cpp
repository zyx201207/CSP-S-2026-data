#include<bits/stdc++.h>
#define fs first
#define sc second
#define int long long
using namespace std;

const int N = 505, M = 5e5 + 5;

int c, n, m, d, q;
int out[M], dis[N][N], k[N], due[M];
struct Amiya{
	int to, w;
};
vector<Amiya> p[M];

signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> out[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			int u, v;
			cin >> u >> v;
			p[u].push_back({i, v});
			due[u]++;
		}
	}
	
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			dis[i][j] = (i == j? 0 : 1e18);
	
	for(int i = 1;i <= m;i++){
		for(int x = 0;x < due[i];x++){
			for(int y = 0;y < due[i];y++){
				if(x == y) continue;
				Amiya &n1 = p[i][x], &n2 = p[i][y];
				dis[n1.to][n2.to] = min(dis[n1.to][n2.to], n1.w + n2.w);
			}
		}
	}
	
	for(int p = 1;p <= n;p++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				dis[i][j] = min(dis[i][j], dis[i][p] + dis[p][j]);
	
	for(int i = 1;i <= q;i++){
		int x, y;
		cin >> x >> y;
		int ans = 1e18;
		for(int p1 = 0;p1 < due[x];p1++)
			for(int p2 = 0;p2 < due[y];p2++){
				Amiya &n1 = p[x][p1], &n2 = p[y][p2];
				ans = min(ans, dis[n1.to][n2.to] + n1.w + n2.w);
			}
		cout << ans + out[x] + out[y] << "\n";
	}
	
	return 0;
	
}
