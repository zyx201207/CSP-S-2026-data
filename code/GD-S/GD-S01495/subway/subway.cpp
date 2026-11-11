#include <bits/stdc++.h>
using namespace std;
#define int long long
int K[505], a[505][1005], t[505][1005], w[1005];
struct edge{
	int u;
	int v;
	int w;
};
vector <edge> e[1005];
int ans[1005][1005];
struct cmp{
	bool operator ()(const edge& A, const edge& B) const{
		return A.w > B.w;
	}
};
priority_queue <edge, vector<edge>, cmp> q;
void dijkstra(int s){
	while(!q.empty()){
		q.pop();
	}
	for(int i = 0; i < e[s].size(); i++){
		q.push(e[s][i]);
	}
	ans[s][s] = 0;
	while(!q.empty()){
		edge f = q.top();
		q.pop();
		if(ans[s][f.v] == 2147483647){
			ans[s][f.v] = ans[s][f.u] + f.w;
			for(int i = 0; i < e[f.v].size(); i++){
				q.push(e[f.v][i]);
			}
		}
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> K[i];
		for(int j = 1; j <= K[i]; j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1; i <= 1004; i++){
		for(int j = 1; j <= 1004; j++){
			ans[i][j] = 2147483647;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= K[i]; j++){
			for(int k = j + 1; k <= K[i]; k++){
				int u, v, w;
				u = a[i][j];
				v = a[i][k];
				w = t[i][j] + t[i][k];
				edge tmp;
				tmp.u = u;
				tmp.v = v;
				tmp.w = w;
				e[u].push_back(tmp);
				tmp.v = u;
				tmp.u = v;
				e[v].push_back(tmp);
			}
		}
	}
	for(int i = 1; i <= q; i++){
		int x, y;
		cin >> x >> y;
		dijkstra(x);
		cout << ans[x][y] + w[x] + w[y] << "\n";
	}
	return 0;
}
