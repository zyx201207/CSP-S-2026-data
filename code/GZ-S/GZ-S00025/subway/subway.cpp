//GZ-S00025 秦子懿 贵阳市白云区华师一学校 
#include <bits/stdc++.h>
using namespace std ;
#define int long long
int c , n , m , D , T ;
int aa ;
//vector<pair<int , int> > e[1000 + 10] , v[1000 + 10] ;
int w[500000 + 10] ;
int t[500 + 10][1000 + 10] ;
vector<int> a[500 + 10] , v[300 + 10] ;
bool f[500 + 10][5000] ;
bool vis[500 + 10] ;
int uu , vv ;
int ans ;
void dfs(int id , int sum){
//	if(f[id][v]) return ;
	if(f[id][vv]){
		for(int i = 0 ; i < (int)a[id].size() ; i ++){
			if(a[id][i] == vv){
				ans = min(ans , sum + t[id][i]) ;
				break ;
			}
		}
	}
	for(int i = 0 ; i <(int)a[id].size() ; i ++){
		int x = a[id][i] ;
		for(int j = 0 ; j < (int)v[x].size() ; j ++){
			int y = v[x][j] ;
			if(vis[y]) continue;
			vis[y] = 1 ;
			for(int k = 0 ; k < (int)a[y].size() ; k ++){
				if(a[y][k] == x){
					aa = k ;
					break ;
				}
			}
			dfs(y , t[id][i] + sum + t[y][aa]) ;
			vis[y] = 0 ;
		}
	}
}
/*
int d[1000 + 10] ;
int dis[1000 + 10][1000 + 10] ;
priority_queue<pair<int , int> , vector<pair<int , int> > , greater<pair<int , int> > > q ;
*/
/*
void dij(int s){
	memset(d , 0x3f , sizeof(d)) ;
	d[s] = 0 ;
	q.push({0 , s}) ;
	while(!q.empty()){
		int x = q.top().second ;
		int ww = q.top().first ;
		q.pop() ;
		if(d[x] != ww) continue ;
		for(int i = 0 ; i < (int)e[x].size() ; i ++){
			int y = e[x][i].first ;
			int w = e[x][i].second ;
			if(ww + w < d[y]){
				d[y] = ww + w ;
				q.push({d[y] , y}) ;
			}
		}
	}
	memcpy(dis[s] , d , sizeof(d)) ;
} 
*/
signed main(){
	freopen("subway.in" , "r" , stdin) ;
	freopen("subway.out" , "w" , stdout) ;
	cin >> c >> n >> m >> D >> T ;
	/*if(c <= 11){
		for(int i = 1 ; i <= m ; i ++) cin >> w[i] ;
		for(int i = 1 ; i <= n ; i ++){
			int k ;
			cin >> k ;
			for(int j = 1 ; j <= k ; j ++){
				int x ;
				cin >> x ;
				a[i].push_back(x) ;
				v[x].push_back({i , j}) ;
			}
			for(int j = 1 ; j <= k ; j ++){
				for(int l = j + 1 ; l <= k ; l ++){
					int x = a[i][j] , y = a[i][l] ;
					e[x].push_back({y , 0}) ;
					swap(x , y) ;
					e[x].push_back({y , 0}) ;
				}
			}
			for(int j = 1 ; j <= k ; j ++) cin >> t[i][j] ; 
		}
		for(int i = 1 ; i <= m ; i ++){
			for(int j = 0 ; j < (int)v[i].size() ; j ++){
				if(a[v[i][j].first].size() == 1) continue ;
				for(int k = j + 1 ; k < (int)v[i].size() ; k ++){
					if(a[v[i][k].first].size() == 1) continue ;
					int x = a[v[i][j].first][0] ;
					int y = a[v[i][k].first][0] ;
					int w = t[v[i][j].first][1] + t[v[i][k].first][1] ;
					if(x == y) x = a[v[i][j].first][1] , w = t[v[i][j].first][2] + t[v[i][k].first][1] ;
					e[x].push_back({x , w})  ;
					swap(x , y) ;
					e[x].push_back({y , w}) ;
				}
			}
		}
		for(int i = 1 ; i <= m;  i ++){
			cout << i << " :\n" ;
			for(int j = 0 ; j < (int)e[i].size() ; j ++) cout << "  " << e[i][j].first << ' ' << e[i][j].second << '\n' ;
			cout << '\n' ;
		}
		for(int i = 1 ; i <= m ; i ++) dij(i) ;
		while(T --){
			int u , v ;
			cin >> u >> v ;
			cout << min(dis[u][v] , dis[v][u]) + w[u] + w[v] << '\n' ;
		}
	} 
	*/
	for(int i = 1 ; i <= m ; i ++) cin >> w[i] ;
	for(int i = 1 ; i <= n ; i ++){
		int k ;
		cin >> k ;
		for(int j = 0 ; j < k ; j ++){
			int x ;
			cin >> x >> t[i][j] ;
			a[i].push_back(x) ;
			v[x].push_back(i) ;
			f[i][x] = 1 ;
		}
	}
	while(T --){
		ans = LONG_MAX ;
		cin >> uu >> vv ;
		for(int i = 1 ; i <= n ; i ++){
			if(!f[i][uu]) continue ;
			for(int j = 0 ; j < (int)a[i].size() ; j ++){
				if(a[i][j] == uu){
					aa = j ;
					break ;
				}
			}
			vis[i] = 1 ;
			dfs(i , t[i][aa]) ;
			vis[i] = 0 ;
		}
		cout << ans + w[uu] + w[vv] << '\n' ;
	}
	return 0 ;
}
