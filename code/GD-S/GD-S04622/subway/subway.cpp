#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int N = 505, M = 5000005;
unordered_map<int, int> mp[N];
int i, j, k, n, m, c, q, d, tt, w[M], u, v;
long long dis[N][N];
vector <int> g[M];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(i=1; i<=m; i++) scanf("%d", &w[i]); 
	for(i=1; i<=n; i++){
		scanf("%d", &k);
		for(int x=1; x<=k; x++){
			scanf("%d%d", &j, &tt);
			mp[i][j] = tt;
			for(auto v : g[j]){
				if(dis[i][v]) dis[v][i] = dis[i][v] = min(dis[i][v], 1ll * tt + mp[v][j]);
				else dis[i][v] = dis[v][i] = 1ll * tt + mp[v][j];
			}
			g[j].push_back(i);
		}
	}
	for(k=1; k<=n; k++){
		for(i=1; i<=n; i++){
			for(j=i+1; j<=n; j++){
				if(dis[i][k] && dis[k][j]){
					if(dis[i][j] == 0 || dis[i][k] + dis[k][j] < dis[i][j])
						dis[j][i] = dis[i][j] = dis[k][j] + dis[i][k];
				}
			}
		}
	}
	while(q--){
		long long ans = 5e18;
		scanf("%d%d", &u, &v);
		for(auto x : g[u])
			for(auto y : g[v])
				ans = min(dis[x][y] + w[u] + w[v] + mp[x][u] + mp[y][v], ans);	
		printf("%lld\n", ans); 
	}
	return 0;
}
