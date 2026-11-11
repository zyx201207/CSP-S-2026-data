#include "bits/stdc++.h"
#define int long long 
#define f(i ,m ,n ,x) for (int i = (m) ,i##end = (n) ; i <= i##end ; i += (x))

const int N = 2e6 + 77 ;
int x[N] ,to[N] ,coef[N] ;

signed main (void) {
	freopen ("migrate.in" ,"r" ,stdin) ;
	freopen ("migrate.out" ,"w" ,stdout) ;
	std :: ios_base :: sync_with_stdio (false) ,
	std :: cin.tie (nullptr) ,std :: cout.tie (nullptr) ;
	
	int c ,t ; std :: cin >> c >> t ; while (t --> 0) {
		int n ,d ; std :: cin >> n >> d ;
		f (i ,1 ,n ,1) std :: cin >> x[i] ;
		f (i ,1 ,n ,1) to[i] = 0 ;
		f (i ,1 ,n ,1) {
			int pos = std :: upper_bound (x + i ,x + n + 1 ,x[i] + d) - x - 1 ;
			if (pos != i) to[i] = pos ;
		}
		//f (i ,1 ,n ,1) std :: cerr << to[i] << " \n"[i == n] ;
		
		int ans = 0 ; f (i ,1 ,n ,1) {
			if (!to[i]) continue ;
			int las = i + 1 ,now = to[i] ;
			f (j ,1 ,n ,1) coef[j] = 0 ;
			f (j ,las ,now ,1) coef[j] = 1 ;
			//if (i == 1) std :: cerr << las << ' ' << now << '\n' ;
			while (to[now]) {
				int nxt = to[now] ,ptr = now ,sum = 0 ;
				//if (i == 1) std :: cerr << ptr << ' ' << nxt << '\n' ;
				for (int k = nxt ; k > now ; k--) {
					while (ptr >= las && x[k] - x[ptr] <= d) {
						//std :: cerr << k << ' ' << ptr << ' ' << las << ' ' << coef[ptr] << '\n' ;
						sum += coef[ptr--] ;
					}
					coef[k] = sum ; //std :: cerr << coef[4] << '\n' ;
				} las = now + 1 ,now = nxt ;
			} f (j ,i + 1 ,n ,1) if (coef[j] == 2) ans++ ;
		} std :: cout << ans << '\n' ;
	}
}
