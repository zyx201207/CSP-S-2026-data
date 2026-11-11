#include<bits/stdc++.h>
#define int long long
#define fin(a) freopen(a, "r", stdin)
#define fout(a) freopen(a, "w", stdout)
using namespace std;
const int N = 1e6 + 10;
int c, n, m, d, q;
vector<pair<int, int> > a[N];
int id[N];
void add(int u, int v, int w){
	a[u].push_back({v, w});
	a[v].push_back({u, w});
}
int dist[N];
bool fl[N];
void dijk(int s){
	for(int i = 0; i <= N; i++) dist[i] = INT_MAX, fl[i] = 0;
	priority_queue<pair<int, int> > q;
	dist[s] = 0, fl[s] = 1;
	q.push({0, s});
	while(!q.empty()){
		auto x = q.top();
		int u = x.second;
		q.pop();
		for(auto v : a[u]){
			if(fl[v.first]) continue;
			if(dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				q.push({dist[v.first], v.first});
				fl[v.first] = 1;
			}
		}
	}
}
signed main(){
	fin("subway.in");
	fout("subway.out");
	cin >> c >> n >> m >> d >> q;
	for(int i = 1, w; i <= m; i++){
		cin >> w;
		add(i, i + (m * ++id[i]), w);
	}
	for(int i = 1, k; i <= n; i++){
		cin >> k;
		vector<int> rd;
		for(int j = 1, v, t; j <= k; j++){
			cin >> v >> t;
			add(v + m, v + m * ++id[v], t);
			rd.push_back(v);
		}
		for(int i = 1; i < k; i++){
			add(rd[i - 1] + m * id[rd[i - 1]], rd[i] + m * id[rd[i]], 0);
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		dijk(x);
		cout << dist[y] << '\n';
	}
	return 0;
}
//16:44£¬±©Á¦60·Ö×óÓÒ 

