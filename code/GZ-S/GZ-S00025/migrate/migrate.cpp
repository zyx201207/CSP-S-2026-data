//GZ-S00025 秦子懿 贵阳市白云区华师一学校 
#include <bits/stdc++.h>
using namespace std ;
#define int long long
int c , T ;
int n , D ;
int a[2000000 + 10] ;
vector<pair<int , int> > e[5000 + 10] ;
struct Node{
	int dis ;
	int cnt ; 
} ;
Node d[10000] ;
int cnt ;
priority_queue<pair<int , int> , vector<pair<int , int> > , greater<pair<int , int> > > q ;
void dij(int s){
	for(int i = 1 ; i <= n ; i ++){
		d[i].dis = 1000000000000000000 ;
		d[i].cnt = 0 ;
	}
	d[s].dis = 0 ;
	d[s].cnt = 1 ;
	q.push({0 , s}) ;
	while(!q.empty()){
		int x = q.top().second ;
		if(q.top().first != d[x].dis){
			q.pop() ;
			continue ;
		}
		q.pop() ;
//		cout << x << '\n' ;
		for(int i = 0 ; i < (int)e[x].size() ; i ++){
			int y = e[x][i].first ;
			if(d[y].dis > d[x].dis + 1){
				d[y].dis = d[x].dis + 1 ;
				d[y].cnt = d[x].cnt ;
				q.push({d[y].dis , y}) ;
			}
			else if(d[y].dis == d[x].dis + 1) d[y].cnt ++ ;
//			cout << "  " << y << ' ' << d[y].dis << ' ' << d[y].cnt << '\n' ;
		}
	}
	for(int i = 1 ; i <= n ; i ++){
//		cout << d[i].dis << ' ' << d[i].cnt << "  " ;
		if(d[i].cnt == 2) cnt ++ ;
	}
//	cout << '\n' ;
}
signed main(){
	freopen("migrate.in" , "r" , stdin) ;
	freopen("migrate.out" , "w" , stdout) ;
	scanf("%lld%lld" , &c , &T) ;
	if(c <= 10){
		while(T --){
			scanf("%lld%lld" , &n , &D) ;
			cnt = 0 ;
			for(int i = 1 ; i <= n ; i ++) scanf("%lld" , &a[i]) ;
			for(int i = 1 ; i <= n ; i ++){
				e[i].clear() ;
				for(int j = i + 1 ; j <= n ; j ++){
					if(a[j] - a[i] > D) break ;
					e[i].push_back({j , 1}) ;
//					e[j].push_back({i , 1}) ;
//					cout << i << ' ' << j << '\n' ;
				}
			}
			for(int i = 1 ; i <= n ; i ++) dij(i) ;
			printf("%lld\n" , cnt) ;
		}
		return 0 ;
	}
	if(c == 11 || c == 12){
		while(T --){
			scanf("%lld%lld" , &n , &D) ;
			for(int i = 1 ; i <= n ; i ++) scanf("%lld" , &a[i]) ;
			int x = (a[2] - a[1]) ;
//			for(int i = 2 ; i <= n ; i ++){
//				if(a[i] - a[i - 1] != x) cout << "=" ;
//			}
			x = D / x ;
			int sum = 0 ;
			for(int i = 1 ; i + x + 1 <= n ; i ++){
				sum += max(0ll , min(n - (i + x) - 1 , x - 1)) ;
//				if(sum != 0) cout << "== " ;
			}
//			cout << D << ' ' << a[2] - a[1] << ' ' << x << ' ' << n << ' ' ;
			printf("%lld\n" , sum) ;
		}
		return 0 ;
	}
	return 0 ;
}
