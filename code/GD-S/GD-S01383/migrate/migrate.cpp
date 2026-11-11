#include <bits/stdc++.h> 
using namespace std ; 
const int N = 5010 ; 
typedef long long ll ; 
ll d[N][N] ; 
ll a[N] ; 
ll cnt[N][N] ; 
ll dis , n ;   
int ans ;  
void bt () {
	for (int k = 1 ; k <= n ; k ++ ) {
		for (int i = 1 ; i <= n ; i ++ ) if (i != k) {
			for (int j = 1 ; j <= n ; j ++ ) if (j != i && j != k ) {
				if (abs(i - j)  <= dis ) {
					if (d[i][j] == 1 ) cnt [i][j] ++ ; 
					else cnt[i][j] = 0 ; 
					d[i][j] = 1 ; 
				} else {
					if (abs(k - i) <= dis ) {
						if (abs(k - j) <= dis ) {
							if (d[i][j] == 2 ) cnt[i][j] ++ ; 
							else if (d[i][j] > 2){
								d[i][j] = 2 ; 	
							}else cnt[i][j] = 0 ; 
						} else {
							if (d[i][j] == abs (j - k) + 1 ) cnt[i][j] ++ ; 
							else if (d[i][j] > abs (j - k) + 1 ){
								d[i][j] = abs (j - k) + 1 ; 	
							}else cnt[i][j] = 0 ;
						}
					} else {
						if (abs(k - j) <= dis ) {
							if (d[i][j] == abs (i - k) + 1 ) cnt[i][j] ++ ; 
							else if (d[i][j] > abs (i - k) + 1 ){
								d[i][j] = abs (i - k) + 1 ; 	
							}else cnt[i][j] = 0 ;
						} else {
							if (d[i][j] == abs (i - k) + abs (k - j) ) cnt[i][j] ++ ; 
							else if (d[i][j] > abs (i - k) + + abs (k - j) ){
								d[i][j] = abs (i - k) + + abs (k - j) ; 	
							}else cnt[i][j] = 0 ;
						}
					}
				}
			}
		}
	} 
}
int main () {
	freopen ("migrate.in" , "r" , stdin ) ; 
	freopen ("migrate.out" , "w" , stdout ) ;
	int c , t ; 
	scanf ("%d%d" , &c , &t ) ; 
	while (t -- ) {
		ans = 0; 
		scanf ("%d%lld" , &n , &d ) ;
		for (int i = 1 ; i <= n ; i ++ ) {
			memset (d[i] , 0 , sizeof (d[i] ) ) ; 
			memset (cnt[i] , 0 , sizeof (cnt[i] ) ) ; 
		}
		for (int i = 1 ; i <= n ; i ++ ) {
			d[i][i] = 0 ; 
			for (int j = 1 ; j <= dis && i + j <= n ; j ++ ) {
				d[j][i] = 1 ; 
				d[i][j] = 1 ; 
			}
		}
		for (int i = 1 ; i <= n ; i ++ ) scanf ("%d" , &a[i] ) ; 
		bt () ; 
		for (int i = 0 ; i <= n ; i ++ ) {
			for (int j = 0 ; j <= n ; j ++ ) {
				ans += (cnt[i][j] == 2 ? 1 : 0 ) ; 
			}
		}
		printf ("%lld\n" , ans ) ; 
	}
	return 0 ; 
}
