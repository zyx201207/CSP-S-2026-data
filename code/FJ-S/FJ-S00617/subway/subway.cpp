#include<bits/stdc++.h>
#define int long long
#define PII pair<int, int>
using namespace std;
const int N = 5e5+10, M = 510;
const int INF = LLONG_MAX;
int c, m, n, dd ,q;
struct edge{
	int b, l;
};
vector<edge> mp[M];
map<int, int> g[N];
int t[N];
int d[M][M];
bool vis[M];
void dijkstra(int s){
	priority_queue<PII, vector<PII>, greater<PII>> q;
	q.push({0, s});
	vis[s] = 1;
	d[s][s] = 0;
	while (!q.empty()){
		int now = q.top().second;
		q.pop();
		vis[now] = 0;
		for (auto i : mp[now]){
			if (d[s][i.b] > d[s][now]+i.l){
				d[s][i.b] = d[s][now]+i.l;
				if (!vis[i.b]){
					vis[i.b] = 1;
					q.push({d[s][i.b], i.b});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld %lld %lld %lld %lld", &c ,&m, &n, &dd, &q);
	for (int i = 1; i <= n; i++)scanf("%lld",&t[i]);
	for (int a = 1; a <= m; a++){
		int k;
		scanf("%lld", &k);
		for (int j = 0; j < k; j++){
			int w, l;
			scanf("%lld %lld", &w, &l);
			g[w][a] = l;
		}
	}
	for (int w = 1; w <= n; w++){
		for (auto a : g[w]){
			for (auto b : g[w]){
				if (a.first == b.first) continue;
				mp[a.first].push_back({b.first, a.second+b.second});
				mp[b.first].push_back({a.first, a.second+b.second});
			}
		}
	}
	for (int i = 0; i < M; i++){
		for (int j = 0; j < M; j++){
			d[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++){
		memset(vis, 0, sizeof(vis));
		dijkstra(i);
	}
	while (q--){
		int x, y;
		cin >> x >> y;
		int temp = INF;
		for (auto i : g[x]){
			for (auto j : g[y]){
				temp = min(temp, d[i.first][j.first]+j.second+i.second);
			}
		}
		printf("%lld\n", t[x]+t[y] + temp);
	}
	return 0;
}
