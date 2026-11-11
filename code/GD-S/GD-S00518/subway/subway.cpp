#include <bits/stdc++.h>
using namespace std;

const long long inf = 0x3f3f3f3f3f3f3f3fll;
long long c, n, m, d, q;
long long w[500005];
struct sta{
	long long id, dis;
};
vector<sta> dis_to_sta[500005];
long long dis_bt_ril[505][505];
struct Edge{
	long long to, val;
};
vector<Edge> e[505];
long long dis[505][505] = {{0}};
bool vis[505] = {0};
void cal(int x){
	for(int i = 1;i <= n;i++)
		dis[x][i] = inf, vis[i] = 0;
	queue<long long> que;
	que.push(x), dis[x][x] = 0;
	while(!que.empty()){
		int u = que.front();
		que.pop();
		if(vis[u])
			continue;
		vis[u] = 1;
		for(int i = 0;i < e[u].size();i++){
			long long v = e[u][i].to, w = e[u][i].val;
			if(dis[x][u] + w < dis[x][v]){
				dis[x][v] = dis[x][u] + w;
				que.push(v);
			}
		}
	}
	return ;
}


int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
	for(int i = 1, k;i <= n;i++){
		cin >> k;
		for(long long j = 1, a, t;j <= k;j++){
			cin >> a >> t;
			dis_to_sta[a].push_back((sta){i, t});
		}
		for(int j = 1;j <= n;j++)
			dis_bt_ril[i][j] = inf;
	}
	for(int i = 1;i <= m;i++){
		int sz = dis_to_sta[i].size();
		for(int j = 0;j < sz - 1;j++)
			for(int k = j + 1;k < sz;k++){
				int x = dis_to_sta[i][j].id, y = dis_to_sta[i][k].id;
				dis_bt_ril[x][y] = min(dis_bt_ril[x][y], dis_to_sta[i][j].dis + dis_to_sta[i][k].dis), dis_bt_ril[y][x] = dis_bt_ril[x][y];
			}
	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			if(dis_bt_ril[i][j] != inf)
				e[i].push_back((Edge){j, dis_bt_ril[i][j]});
	for(int i = 1;i <= n;i++)
		cal(i);
	for(int Q = 1, x, y;Q <= q;Q++){
		cin >> x >> y;
		long long ans = inf;
		for(int i = 0;i < dis_to_sta[x].size();i++){
			int u = dis_to_sta[x][i].id;
			for(int j = 0;j < dis_to_sta[y].size();j++){
				int v = dis_to_sta[y][j].id;
				ans = min(ans, dis[u][v] + w[x] + w[y] + dis_to_sta[x][i].dis + dis_to_sta[y][j].dis);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
