#include "bits/stdc++.h"
#define int long long 
#define f(i ,m ,n ,x) for (int i = (m) ,i##end = (n) ; i <= i##end ; i += (x))

const int N = 1e6 + 77 ;
int n ,a[N] ,m ;
std :: map < int ,int > buc ;

signed main (void) {
	freopen ("crystal.in" ,"r" ,stdin) ;
	freopen ("crystal.out" ,"w" ,stdout) ;
	std :: ios_base :: sync_with_stdio (false) ,
	std :: cin.tie (nullptr) ,std :: cout.tie (nullptr) ;
	
	std :: cin >> n >> m ;
	static std :: vector < int > v ;
	f (i ,1 ,n ,1) std :: cin >> a[i] ,
		buc[a[i]]++ ,v.emplace_back (a[i]) ;
	std :: sort (v.begin () ,v.end ()) ,
	v.erase (std :: unique (v.begin () ,v.end ()) ,v.end ()) ;
	
	int sz = v.size () ; int ans = buc[v[0]] ,cst = 0 ,ptr = 0 ,cnt = buc[v[0]] ,now = buc[v[0]] ;
	f (i ,1 ,sz - 1 ,1) {
		int x = v[i] ;
		cst += cnt * (x - v[i - 1]) ;
		//std :: cerr << "melo " << x << ' ' << cst << '\n' ;
		while (cst > m) {
			int c = x - v[ptr] ;
			int num = (cst - m) / c ;
			if (c * num != cst - m) num++ ;
			if (num >= now) cst -= now * c ,cnt -= now ,now = buc[v[++ptr]] ;
			else cst -= num * c ,cnt -= num ,now -= num ; 
		} ans = std :: max (ans ,cnt += buc[x]) ;
		//std :: cerr << x << ' ' << cnt << ' ' << cst << '\n' ;
	} std :: cout << ans << '\n' ;
}
