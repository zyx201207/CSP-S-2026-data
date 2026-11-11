#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200005;
int c, t, n, d;
int x[N];
vector<pair<int, int>> e[N];
void init(){
	for (int i = 1; i <= n; i++){
		e[i].clear();
	}
}
int dis[N];
bool vis[N];
int cnt[N];
void dijkstra(int S){ //dijkstra
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, false, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	dis[S] = 0;
	q.push({0, S});
	while (!q.empty()){
		auto tmp1 = q.top();
		q.pop();
//		if (vis[tmp1.second])
//			continue;
//		vis[tmp1.second] == 
		for (auto tmp2 : e[tmp1.second]){
			if (dis[tmp2.first] == dis[tmp1.second] + 1){
				cnt[tmp2.first]++;
				q.push({dis[tmp2.first], tmp2.first});
			}
			if (dis[tmp2.first] > dis[tmp1.second] + 1){
				dis[tmp2.first] = dis[tmp1.second] + 1;
				cnt[tmp2.first] = 1;
				q.push({dis[tmp2.first], tmp2.first});
			}
		}
	}
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	for (int cs = 1; cs <= t; cs++){
		cin >> n >> d;
		init();
		for (int i = 1; i <= n; i++){
			cin >> x[i];
		}
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				if (abs(x[j] - x[i]) <= d){
					e[i].push_back({j, abs(x[j] - x[i])});
					e[j].push_back({i, abs(x[j] - x[i])});
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = i + 3; j <= n; j++){
				dijkstra(i);
				if (cnt[j] == 2){
					ans++;
				}
			} 
		}
		cout << ans << "\n";
	}
}
