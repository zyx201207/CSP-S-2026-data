#include <iostream>
#include <vector>
#include <queue>
#define int long long
#define pii pair<int, int>
#define fir first
#define sec second
#define mk_p make_pair
using namespace std;
constexpr int M = 500005;

int c, n ,m, d, Q, wh[M], a[M], t[M];
int dis[5005][5005]; 
bool book[M];
vector<pii> edge[M << 2];
priority_queue<pii> q;

inline void dij(int s){
	dis[s][s] = 0;
	q.push(mk_p(0, s));
	while (q.size()){
		int u = q.top().sec;
		q.pop();
		if (book[u]) continue;
		book[u] = 1;
		for (auto t : edge[u]){
			int v = t.fir, w = t.sec;
			if(dis[s][u] + w < dis[s][v]){
				dis[s][v] = dis[s][u] + w;
				q.push(mk_p(-dis[s][v], v));
			}
		}
	}
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++){
		cin >> wh[i];
		edge[i].push_back(mk_p(i + m, wh[i]));
		edge[i + m].push_back(mk_p(i, wh[i]));
	}
	int cnt = 2 * m;
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++){
			cin >> a[j] >> t[j];
			cnt++;
			edge[a[j] + m].push_back(mk_p(cnt, t[j]));
			edge[cnt].push_back(mk_p(a[j] + m, t[j]));
			a[j] = cnt;
		}
		for (int j = 2; j <= k; j++){
			edge[a[j - 1]].push_back(mk_p(a[j], 0));
			edge[a[j]].push_back(mk_p(a[j - 1], 0));
		}
	}
	if(c <= 11){
		for (int i = 0; i <= 4 * m; i++){
			for (int j = 0; j <= 4 * m; j++){
				dis[i][j] = 1e18;
			}
			book[i] = 0;
		}
		for (int i = 1; i <= m; i++){
			for (int j = 0; j <= 4 * m; j++){
				book[j] = 0;
			}
			dij(i);
		}
		while (Q--){
			int u, v;
			cin >> u >> v;
			cout << dis[u][v] << "\n";
		}
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
*/
