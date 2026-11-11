#include <bits/stdc++.h>

#define ll long long
#define N 200005
#define E 20000005 
#define INF 0x3f3f3f3f
using namespace std ;
int c , T , n , tot , hd[N] ;
ll a[N] , d ;
int dis[N] ;
bool vis[N] ;
struct edge {
	int v , w , nxt ;
}e[E] ;
void doit(int s) {
	priority_queue<pair<int , int> > q ;
	for(int i = 1 ; i <= n ; i++)dis[i] = INF , vis[i] = 0 ;
	dis[s] = 0 ;
	q.push({0 , s}) ;
	while(!q.empty()) {
		int u = q.top().second ;
		q.pop() ;
		if(vis[u])continue ;
		vis[u] = 1 ;
		for(int i = hd[u] ; i ; i = e[i].nxt) {
			int v = e[i].v ;
			if(dis[v] > dis[u] + e[i].w) {
				dis[v] = dis[u] + e[i].w ;
				q.push({-dis[v] , v}) ;
			} 
		}
	}
	
}
int lst ;
ll ans ;
int cnt[N] ;
void solve1() {
	for(int i = 1 ; i <= n ; i++)hd[i] = vis[i] = 0 ;
	tot = ans = 0 ;
	
	int l = 1 ;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i] ;
		while(a[i] - a[l] > d && l < i)l++ ; 
		if(a[i] - a[l] <= d) {
			for(int j = l ; j < i ; j++) {
				e[++tot] = {i , 1 , hd[j]} ;
				hd[j] = tot ;
				e[++tot] = {j , 1 , hd[i]} ;
				hd[i] = tot ;
			}
		}
	}
	for(int i = 1 ; i <= n ; i++) {
		doit(i) ;
		for(int j = 1 ; j <= n ; j++)cnt[j] = vis[j] = 0 ;
		queue<int> q ;
		q.push(i) ;
		cnt[i] = 1 ;
		vis[i] = true ;
		while(!q.empty()) {
			int u = q.front() ;
			q.pop() ;
			for(int j = hd[u] ; j ; j = e[j].nxt) {
				int v = e[j].v ;
				if(dis[v] == dis[u] + 1) {
					cnt[v] += cnt[u] ;
				}
				if(!vis[v]) {
					q.push(v) ;
					vis[v] = true ;
				}
			}
		}
		for(int j = i + 1 ; j <= n ; j++) {
			if(cnt[j] == 2) {
				ans++ ;
			//	cout << i <<" " << j << '\n' ;
			}
			
		}
	}
	cout << ans << '\n' ;
}
int main() {

	ios :: sync_with_stdio(false) ;
	cin.tie(0) , cout.tie(0) ;

	freopen("migrate.in" , "r" , stdin) ;
	freopen("migrate.out" , "w" , stdout) ;

	cin >> c >> T ;
	while(T --) {
		cin >> n >> d ;
	//	cout << T << '\n' ;
		solve1() ;
	}
	return 0 ;

}
/*
0 1
4 2
1 2 3 4

0 1
8 3
0 1 2 4 8 10 11 13

*/ 
