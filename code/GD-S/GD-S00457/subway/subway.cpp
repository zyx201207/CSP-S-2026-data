#include <bits/stdc++.h>

#define ll long long
#define N 505 
#define M 600005
#define E 20000005 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std ;
int m , n , d , Q , op , k[N] , hd[M] , w[M] , tot ;
vector<int> a[N] , t[N] ;
struct edge {
	int v , w , nxt ;
}e[E] ;
ll op1[5005][5005] ;
ll dis[M] ;
bool op2 = true ;
bool vis[M] ;
void doit(int s) {
	priority_queue<pair<ll , int> > q ;
	for(int i = 1 ; i <= m + n ; i++)dis[i] = INF , vis[i] = 0 ;
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
void solve1() {
	memset(op1 , INF , sizeof(op1)) ;
	for(int i = 1 ; i <= m ; i++) {
		doit(i) ;
		for(int j = 1 ; j <= m ; j++) {
			op1[i][j] = dis[j] ;
	//		cout << i <<" " << j <<" " << op1[i][j] << '\n' ;
		}	
	}
	while(Q --) {
		int x , y ;
		cin >> x >> y ;
		cout << op1[x][y] + w[x] + w[y] << '\n' ;
	}
}
int sum , lst ;
int main() {
	
	ios :: sync_with_stdio(false) ;
	cin.tie(0) , cout.tie(0) ;
	
	freopen("subway.in" , "r" , stdin) ;
	freopen("subway.out" , "w" , stdout) ;
	cin >> op >> n >> m >> d >> Q ;
	for(int i = 1 ; i <= m ; i++)cin >> w[i] ;
	for(int i = 1 ; i <= n ; i++) {
		cin >> k[i] ;
		sum += k[i] ;
		if(k[i] == 1)continue ;
		for(int j = 0 , x , y ; j < k[i] ; j++) {
			cin >> x >> y ;
			a[i].push_back(x) ;
			e[++tot] = {x , y , hd[i + m]} ;
			hd[i + m] = tot ;
			e[++tot] = {i + m , y , hd[x]} ;
			hd[x] = tot ;
			if(lst != 0 && lst != y) op2 = false ;
			lst = y ;
		//	cout << x << " " << i + m <<" " << y << '\n' ;
			
		}
	}
	if(sum <= 5000) {
		solve1() ;
		return 0 ;
	}
//	for(int i = 1 ; i <= n ; i++)cout << pr[i] << " " ;
//	cout << '\n' ;
	
	while(Q--) {
		int x , y ;
		cin >> x >> y ;
		doit(x) ;
		cout << dis[y] + w[x] + w[y] << '\n' ;
	}
	 
	 
	return 0 ;
	
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 
  7 4 6
3 2 3 3 
  4 5 7
1 3
1 2



*/
