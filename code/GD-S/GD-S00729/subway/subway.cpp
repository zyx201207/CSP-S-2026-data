#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<pair<int, int> > G[505];
int W[500005], a[505][505], t[505][505], d[505];
int f(int s, int t){
	memset(d, 0x3f, sizeof(d));
	queue<int> q;
	q.push(s);
	d[s] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto e : G[u]){
			int v = e.first, w = e.second;
			if(d[u] + w < d[v]){
				d[v] = d[u] + w;
				q.push(v);
			}
		}
	}
	return d[t];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	int c, n, m, D, q;
	cin >> c >> n >> m >> D >> q;
	for(int i = 1; i <= m; i++) cin >> W[i];
	for(int i = 1; i <= n; i++){
		int K;
		cin >> K;
		for(int j = 1; j <= K; j++) cin >> a[i][j] >> t[i][j];
		for(int j = 1; j < K; j++){
			for(int k = j + 1; k <= K; k++){
				G[a[i][j]].push_back({a[i][k], t[i][j] + t[i][k]});
				G[a[i][k]].push_back({a[i][j], t[i][j] + t[i][k]});
			}
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		cout << f(x, y) + W[x] + W[y] << '\n';
	}
	return 0;
}
