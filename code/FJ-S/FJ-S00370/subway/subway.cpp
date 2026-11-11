#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int , int>
const int N = 5e2 + 10 , M = 5e3 + 10;
int dist[N] , h[N] , k[N];
int a[N][M] , t[N][M];
int c , n , m , d , q;
vector<PII> g[N];
void dij(int s){
	for(int i = 1 ; i <= n ; i ++) dist[i] = 1e18;
	dist[s] = 0;
	priority_queue<PII , vector<PII> , greater<PII>> q;
	q.push({0 , s});
	while(q.size()){
		auto t = q.top();
		q.pop();
		int d = t.first , u = t.second;
		if(d > dist[u]) continue;
		for(auto x : g[u]){
			int v = x.first , w = x.second;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				q.push({dist[v] , v});
			}
		}
	}
}
void add(int a , int b , int c){
	g[a].push_back({b , c});
}
signed main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i ++) cin >> h[i];
	for(int i = 1 ; i <= n ; i ++){
		cin >> k[i];
		for(int j = 1 ; j <= k[i] ; j ++){
			cin >> a[i][j] >> t[i][j];
		}
		for(int j = 1 ; j + 1 <= k[i] ; j ++){
			add(a[i][j] , a[i][j + 1] , t[i][j]);
			add(a[i][j + 1] , a[i][j] , t[i][j]);
		}
	}
	while(q --){
		int s , tt;
		cin >> s >> tt;
		if(n <= 3){
			int ans = h[s];
			for(int i = 1 ; i <= n ; i ++){
				for(int j = 1 ; j <= k[i] ; j ++){
					if(a[i][j] == tt){
						ans += t[i][j];
						break; 
					}
				}
			}
			ans += h[tt];
			cout << ans << '\n';
			continue;
		}
		dij(s);
		cout << dist[tt] << '\n';
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
