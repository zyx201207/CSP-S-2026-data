#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 5e2 + 10;
int g[N][N];
int w[N], t[N][N];
vector<int> p[N];
int dij(int s, int s1){
	int dis[N][N];
	memset(dis, 0x3f, sizeof(dis));
	queue<pair<int, int> > q;
	for(size_t i = 0; i < p[s].size(); i++){
		q.push({s, p[s][i]});
		dis[s][p[s][i]] = t[s][p[s][i]];
	}
	while(!q.empty()){
		int u = q.front().first, l1 = q.front().second;
		q.pop();
		int v = g[l1][u];
		for(size_t i = 0; i < p[v].size(); i++){
			int l2 = p[v][i];
			if(l1 == l2){
				if(dis[u][l1] < dis[v][l1]){
					dis[v][l1] = dis[u][l1];
					q.push({v, l1});
				}
			}else{
				int num = t[v][l1] + t[v][l2];
				if(dis[u][l1] + num < dis[v][l2]){
					dis[v][l2] = dis[u][l1] + num;
					q.push({v, l2});
				}
			}
		}
	}
	int ans = INF;
	for(size_t i = 0; i < p[s1].size(); i++){
		ans = min(ans, dis[s1][p[s1][i]]);	
	}
	return ans;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		int ai1, ti1;
		cin >> ai1 >> ti1;
		t[i][ai1] = ti1;
		p[ai1].push_back(i);
		for(int j = 2; j <= k; j++){
			int a, T;
			cin >> a >> T;
			t[a][i] = T;
			g[i][ai1] = a;
			ai1 = a;
			p[ai1].push_back(i);
		}
	}
	for(int i = 1; i <= q; i++){
		int u, v;
		cin >> u >> v;
		cout << dij(u, v) + w[u] + w[v] << endl;
	}
	return 0;
}
