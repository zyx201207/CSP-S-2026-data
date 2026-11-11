#include<bits/stdc++.h>
using namespace std;
const int N = 2e4 + 100 , M = 4e6 + 100 ;
int c , n , m , d , q ;
int dis[N] , solve_answer = 0x3f3f3f3f ;
bool vis[N] ;
map<int,int>mp[M] ;
map<bool,int>xian_[M] ; 
struct node { int stations , dis_time ; };
vector<node>g[M] ;
vector<int>turn[M] ;
void dfs( int staion , int endstaion , int answer , int xianlu ) {
	if( staion == endstaion ) {
		solve_answer = min( answer + mp[xianlu][endstaion] + dis[endstaion] , solve_answer ) ;
		return ;
	}
	vis[staion] = true ;
	for( auto v : g[staion] ) {
		if( vis[v.stations] ) continue ;
		vis[v.stations] = true ;
		dfs( v.stations , endstaion , answer + v.dis_time , xian_[staion][v.stations] ) ;
	}
}
int main() {
	freopen( "subway.in" , "r" , stdin ) , freopen( "subway.out" , "w" , stdout ) ;
	ios::sync_with_stdio(0) , cin.tie(0) ;
	cin>>c>>n>>m>>d>>q ;
	for( int i = 1 ; i <= m ; i++ ) cin>>dis[i] ;
	for( int i = 1 ; i <= n ; i++ ) {
		int k , last , last_ , station , disss ;
		cin>>k>>last>>last_ ;
		mp[i][last] = last_ ;
		turn[last].push_back(i) ;
		for( int j = 2 ; j <= k ; j++ ) {
			cin>>station>>disss ;
			if( turn[last].size() > 1 ) {
				for( auto xian : turn[last] ) {
					xian_[last][station] = xian ;
					xian_[station][last] = i ;
					g[last].push_back( { station , last_ + mp[xian][j] } ) ;
					g[station].push_back( { last , disss + mp[xian][j] } ) ;
				} 
			}else {
				xian_[last][station] = xian_[station][last] = i ;
				g[last].push_back( { station , last_ } ) ;
				g[station].push_back( { last , disss } ) ;
			} 
			mp[i][station] = disss ;
			turn[station].push_back(i) ,  last = station , last_ = disss ;
		}
	} 
	while( q-- ) {
		memset( vis , false , sizeof( vis ) ) ;
		int start , end ;
		cin>>start>>end ;
		dfs( start , end , dis[start] , 0 ) ;
		cout<<solve_answer<<"\n" ;
	}
	return 0 ;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
