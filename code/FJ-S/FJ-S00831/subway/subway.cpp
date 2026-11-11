#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505;
const int M = 5e5+5;
typedef pair<int, int> pii;
int c, n, m, d, q, w[N], dis[N][N];
int pass[M][25], t[M][25], cnt[M];
//pass[i][j]，经过i号地铁站的线路
//cnt[i]，经过i号地铁站的线路数量 
//dis[i][j],从i号线到j号线的时间 
vector<pii> e[N];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++) scanf("%lld", &w[i]);
	for(int i = 1, k; i <= n; i++){
		scanf("%lld", &k);
		for(int j = 1, v, w; j <= k; j++){
			scanf("%lld%lld", &v, &w);
			pass[v][++cnt[v]] = i; 
			t[v][cnt[v]] = w;
		}
	}
	//同一个线路中的点，dis=0
	//总共500条线路，其实我们只要求出线路之间的距离就够了， 
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			dis[i][j] = dis[j][i] = 1e10;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= cnt[i]; j++)
			for(int k = j + 1; k <= cnt[i]; k++){
				int u = pass[i][j], v = pass[i][k];
				int ww = t[i][j] + t[i][k];
				dis[u][v] = dis[v][u] = min(dis[u][v], ww);
			}
	}//直接换乘
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++) 
			for(int j = i + 1; j <= n; j++)
				dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(q--){
		int x, y;
		scanf("%lld%lld", &x, &y);
		int ans = 2e9;
		for(int i = 1; i <= cnt[x]; i++)
			for(int j = 1; j <= cnt[y]; j++){
				int u = pass[x][i], v = pass[y][j];
				ans = min(ans, t[x][i] + dis[u][v] + t[y][j]);
			}
		printf("%lld\n", w[x] + ans + w[y]);
	}
	return 0;
}
