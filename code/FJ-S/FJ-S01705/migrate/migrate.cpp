#include <iostream>
#include <queue>
#define int __int128
using namespace std;
constexpr int N = 2000006;

int x[N], dis[N];
long long c, T, n, d, cnt[N];
queue<int> q;

inline void bfs(int s){
	for (int i = 1; i <= n; i++){
		dis[i] = 1e19;
	}
	dis[s] = 0, cnt[s] = 1;
	q.push(s);
	while(q.size()){
		int u = q.front();
		q.pop();
		for (int v = u + 1; v <= n; v++){
			if(x[v] - x[u] > d) break;
			if(dis[u] + 1 < dis[v]){
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
		for (int v = u - 1; v >= 1; v--){
			if(x[u] - x[v] > d) break;
			if(dis[u] + 1 < dis[v]){
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
}

int dfs(int u, int fa, int ed, int w){
	if(u == ed){
		if(w == dis[ed]) return 1;
		else return 0;
	}
	int s = 0;
	for (int v = u + 1; v <= n; v++){
		if(v == fa) continue;
		s += dfs(v, u, ed, w + 1);
	}
	return s;
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--){
		cin >> n >> d;
		int ans = 0;
		long long ct;
		for (int i = 1; i <= n; i++){
			cin >> ct;
			x[i] = ct;
		}
		if(c <= 2){
			for (int x = 1; x <= n; x++){
				bfs(x);
				for (int y = x + 1; y <= n; y++){
					int val = dfs(x, 0, y, 0);
					if(val == 2) ans++;
				}
			}
		}
		cout << (long long)ans << "\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

