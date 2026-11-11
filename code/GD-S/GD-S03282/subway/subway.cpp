#include <bits/stdc++.h>
using namespace std;
const int MAXM = 1e4*500+10, MAXN = 510;
//测试点编号、地铁线路数、
//地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
int c;
int n, m, d;
int q;
int w[MAXM];
int k[MAXN];
int a[MAXN][MAXN];
int t[MAXN][MAXN];
vector <pair<int, int> > route[MAXM];//每个站台有的换乘线路，以及花费步行时间 
long long dist[MAXN][MAXN];//线路与线路的最小换乘时间
//vector <pair<int, int> > mapp[MAXN];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dist, 0x3f3f3f3f, sizeof(dist));
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++){
		dist[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++){
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
			route[a[i][j]].push_back({i, t[i][j]});
		}
	}
	for (int i = 1; i <= m; i++){
		//printf("u:%d: ", i);
		for (int x = 0; x < route[i].size(); x++){
			for (int y = x+1; y < route[i].size(); y++){
				int u = route[i][x].first, v = route[i][y].first;
				long long dis = route[i][x].second + route[i][y].second;
				//cout << d;
				dist[u][v] = min(dist[u][v], dis); 
			}
			//printf("%d ", route[i][x]);
		}
		//printf("\n");
	}
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = i+1; j <= n; j++){
			dist[j][i] = dist[i][j];
			//printf("%d->%d: %lld \n", i, j, dist[i][j]);
		}
	}
	/*for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			printf("%d->%d: %lld \n", i, j, dist[i][j]);
		}
	}*/
	//cout << 1;
	for (int op = 1; op <= q; op++){
		//cout << 1;
		int x, y;
		cin >> x >> y;
		//cout << 1;
		long long ans = w[x] + w[y];
		long long dis = 0x3f3f3f3f;
		
		//cout << ans << " ";
		for (int i = 0; i < route[x].size(); i++){
			for (int j = 0; j < route[y].size(); j++){
				int u = route[x][i].first, v = route[y][j].first;
				long long distance = route[x][i].second + route[y][j].second;
				//printf("%d %d %lld\n", u, v, distance);
				dis = min(dis, distance+dist[u][v]);
			}
		}
		ans += dis;
		//cout << x << " " << y << " " << ans << " ";
		cout << ans << endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
