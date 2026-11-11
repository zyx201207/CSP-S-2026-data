#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
const ll INF = 1e18;
const int mod = 1e9 + 7;
#define pii pair<ll , ll>

int c , n , m , d , Q;
ll w[N] , dis[N + 500] , ans[N];
vector<pii> e[N + 500];
vector<pii> x[N];

void dijkstra(int pos){
	priority_queue<pii> q;
	for(int i = 1 ; i <= n + m ; i++) dis[i] = INF;
	ll v , w;
	for(int i = 0 ; i < e[pos].size() ; i++){
		v = e[pos][i].first , w = e[pos][i].second;
		dis[v] = min(dis[v] , w);
		q.push({w , v});
	}
	while(!q.empty()){
		pii now = q.top();
		q.pop();
		int u = now.second;
		for(int i = 0 ; i < e[u].size() ; i++){
			v = e[u][i].first , w = e[u][i].second;
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				q.push({w , v});
			}
		}
	}
}

int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1 ; i <= m ; i++){
		cin >> w[i];
	}
	for(int i = 1 , k ; i <= n ; i++){
		cin >> k;
		for(int j = 1 , a , t ; j <= k ; j++){
			cin >> a >> t;
			e[m + i].push_back({a , t});
			e[a].push_back({m + i , t});
		}
	}
	int a , b;
	for(int i = 1 ; i <= Q ; i++){
		cin >> a >> b;
		x[a].push_back({b , i});
	}
	for(int i = 1 ; i <= m ; i++){
		if(x[i].size() == 0) continue;
		dijkstra(i);
		for(int j = 0 , y ; j < x[i].size() ; j++){
			y = x[i][j].first;
			ans[x[i][j].second] = w[i] + w[y] + dis[y];
		}
	}
	for(int i = 1 ; i <= Q ; i++){
		cout << ans[i] << '\n';
	}
	return 0;
} 


/*
FC /W D:\GD-S04703\subway\subway.ans D:\GD-S04703\subway\subway.out
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
