#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+9;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int ID, n, m, d, q;
ll w[N], dis[509][509];
struct Node{
	int ln;
	ll t;
};
vector<Node> g[N];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> ID >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	memset(dis, inf, sizeof(dis));
	for(int i = 1, ki; i <= n; i++){
		cin >> ki;
		dis[i][i] = 0;
		for(int j = 1, aij, tij; j <= ki; j++){
			cin >> aij >> tij;
			g[aij].push_back({i, tij});
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < g[i].size(); j++){
			for(int k = j+1; k < g[i].size(); k++){
				int u = g[i][j].ln, v = g[i][k].ln;
				dis[u][v] = dis[v][u] = min(dis[u][v], g[i][j].t+g[i][k].t);
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
			}
		}
	}
	int x, y;
	ll ans;
	while(q--){
		ans = inf;
		cin >> x >> y;
		for(int i = 0; i < g[x].size(); i++){
			for(int j = 0; j < g[y].size(); j++){
				ans = min(ans, dis[g[x][i].ln][g[y][j].ln] + g[x][i].t + g[y][j].t + w[x] + w[y]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
