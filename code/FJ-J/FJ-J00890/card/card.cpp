#include <bits/stdc++.h>
using namespace std ;

struct card {
	int in , pos ;
};

long long n , m , a[500500] , ans[300300] ;
card d[300300] ;

int main ()
{
	freopen("card.in" , "r" , stdin) ;
	freopen("card.out" , "w" , stdout) ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i] ;
	}
	for (int num = 1 ; num <= n ; num++) {
		for (int i = num ; i <= n ; i++) {
			d[a[i]].in++ ;
			if (d[a[i]].in >= 2) {
				for (int j = 1 ; j <= i ; j++) {
					if (d[a[i]].pos <= d[j].pos && d[j].pos <= i) {
						d[j].pos = 0 ; d[j].in = 0 ;
					}
				}
				d[a[i]].in = 1 ;
			}
			d[a[i]].pos = i ;
		}
		for (int i = 1 ; i <= m ; i++) {
			//cout << d[i].in << " " << d[i].pos << endl ;
			if (d[i].in == 1) {
				ans[i]++ ;
			}
			d[i].in = 0 ; d[i].pos = 0 ;
		}
		//cout << endl ;
	}
	for (int i = 1 ; i <= m ; i++) {
		cout << ans[i] << " " ;
	}
	
	return 0 ;
}
