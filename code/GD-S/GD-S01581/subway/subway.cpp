#include<bits/stdc++.h>
using namespace std;
const int N = 505 , M = 1005 ;
int c , n , m , d , q , w[M] , dist[M] ;
#define pii pair<int,int> 
int a[N][M] , t[N][M] , ko[M] , f[M][M] , fop[M][M] , fop1[M][M] , fo[N][M] , top[M];
vector<int> g[N];
vector<pii> v[M];
bool fun ( int u , int v ) {
	bool cnt[25] , cnt2[25];
	memset ( cnt , 0 , sizeof cnt );
	memset ( cnt2 , 0 , sizeof cnt2 );
	for ( auto e : g[u] ) cnt[e] = 1;
	for ( auto e : g[v] ) cnt2[e] = 1;
	for ( auto e : g[u] ) {
		if ( cnt[e] && cnt2[e] ) return true;
	}
	return false;
}
bool fun2 ( int u , int v ) {
	bool cnt2[25];
	memset ( cnt2 , 0 , sizeof cnt2 );
	for ( auto e : g[v] ) cnt2[e] = 1;
	if ( cnt2[u] ) return true;
	return false;
}
int fun1 ( int u , int v ) {
	bool cnt[25] , cnt2[25];
	memset ( cnt , 0 , sizeof cnt );
	memset ( cnt2 , 0 , sizeof cnt2 );
	for ( auto e : g[u] ) cnt[e] = 1;
	for ( auto e : g[v] ) cnt2[e] = 1;
	for ( auto e : g[u] ) {
		if ( cnt[e] && cnt2[e] ) return e;
	}
	return 0;
}
int fun3 ( int u , int v ) {
	bool cnt[25] , cnt2[25];
	memset ( cnt , 0 , sizeof cnt );
	memset ( cnt2 , 0 , sizeof cnt2 );
	for ( auto e : g[v] ) cnt2[e] = 1;
	for ( auto e : g[v] ) {
		if ( e != u && cnt2[e] ) return e;
	}
	return 0;
}
int dij ( int s ) {
	memset ( dist , 0x3f , sizeof dist ) ;
	priority_queue< pii , vector<pii> , greater<pii>> q;
	q.push({0 , s});
	dist[s] = 0;
	int y = top[s];
	while ( !q.empty() ) {
		int p = q.top().second;
		q.pop();
		for ( auto e : v[p] ) {
			int u = e.first , v = e.second;
			if ( dist[v] > dist[p] + u ) {
				if ( !fun2(y , v) && u == 0 ) continue;
				if ( u == 0 ) y = fun1(y , v);
				else y = fun3( y , v ) ;
				dist[v] = dist[p] + u ;
				q.push({dist[v] , v});
				ko[v] = y;
			} 
		}
	}
	return y;
}
int main() {
	freopen("subway.in" , "r" , stdin ) ;
	freopen("subway.out" , "w" , stdout );
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for ( int i = 1; i <= m ;i ++ ) cin >> w[i];
	for ( int i = 1; i <= n ; i ++ ) {
		int k ; cin >> k;
		for ( int j = 1 ; j <= k  ; j ++ ) {
			cin >> a[i][j] >> t[i][j];
			top[a[i][j]] = i;
			g[a[i][j]].push_back(i);
			fop[0][a[i][j]] = t[i][j];
			fo[a[i][j]][i] = t[i][j];
			if ( j != 1 ) {
				v[a[i][j - 1]].push_back({0 , a[i][j]});
				fop[a[i][j - 1]][a[i][j]] = t[i][j];
				fop1[a[i][j - 1]][a[i][j]] = t[i][j - 1];
				f[a[i][j - 1]][a[i][j]] = 1 ;
			}
		}
	}
	for ( int k = 1; k <= m ;k ++ ) {
		for ( int i = 1; i <= m ; i ++ ) {
			for ( int j = 1 ; j <= m ; j ++ ) {
				if ( f[i][k] && f[k][j] ) {
					f[i][j] = 1;
					if ( !fun (i , j) ) {
				 		v[i].push_back({fop[i][k] + fop1[k][j] , j});
				 		v[j].push_back({fop[i][k] + fop1[k][j] , i});
					}
				}
			}
		}
	}
	while ( q -- ) {
		int u , v ; cin >> u >> v;
		int y = dij(u);
		cout << w[u] + w[v] + fop[0][u] + fo[v][ko[v]] + dist[v] << "\n";
	}
	return 0;
}
