//bao li
#include <bits/stdc++.h>
using namespace std ;
const int MAXN = 500005 , MAXM = 300005 ;
//struct node {
//	int w , id ;
//	operator const < (const node& r) const{
//		return w < r.w ;
//	}
//};
int n , m ;
int a[MAXN] , sum [MAXM] ;
int l , r ;

//set <node> s ;
queue <int> q ;
int main () {
	freopen ("card.in","r",stdin) ;
	freopen ("card.out","w",stdout) ; 
	
	ios::sync_with_stdio (false) ;
	cin.tie(0) , cout.tie(0) ; 
	
	cin >> n >> m ;
	
	for ( int i = 1 ; i <= n ; i ++ ) cin >> a[i] ;
	
	//ÌØÊâÐÔÖÊA
//	if (check()) {
//		
//	}
	
		
	
	l = n , r = n ;
	
	for ( int k = n ; k >= 1 ; k -- ) {
//		int now_s = s.size() ;
//		s.insert (a[k]) ;
//		l = k ;
//		if (s.size() == now_s) {










//			
//		}
		bool f = false ;
		for ( int i = 1 ; i <= q.size() ; i ++ ) {
			int nn = q.front () ;
			if (a[k] == q.front()) f = true ;
			q.pop () ;
			q.push (nn) ;
		}
		
		
		
		
		
		if (f) {
			queue <int> q1 ;
			while (q.front () != a[k]){
				q1.push (q.front()) ;
				q.pop () ;
			}
			q = q1 ;
//			q.pop () ;
		}
		q.push (a[k]) ;
		
//		cout << "f=" << f << "q.size()=" << q.size() << "\n" ;
		
		for ( int i = 1 ; i <= q.size () ; i ++ ) {
			int nn = q.front () ;
			q.pop () ;
			q.push (nn) ;
			sum[nn] ++ ;
		}
	}
	
	for ( int i = 1 ; i <= m ; i ++ ) cout << sum[i] << " " ;
	
	
	return 0 ;
} 
