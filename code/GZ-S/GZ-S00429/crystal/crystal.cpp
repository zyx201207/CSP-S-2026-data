//GZ-S00429   李培昊   遵义四中
#include <bits/stdc++.h>
using namespace std;

long long a[500005] ;
long long b[500005] ; 
long long ans , tans ;
long long k , m ;
bool f = true , f2 = true ;
long long m2 ;
long long sum , sum2 ;

int main() {

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	long long n ;



	cin >> n >> m ;

	for( int i = 1 ; i <= n ; i++ ) {

		cin >> a[i] ;

		sum += a[i] ;

		if( a[i] != a[i - 1] && i > 1 ) {

			f = false ;

		}

	}

	sum = ( sum / n ) + 1 ;

	if( f == true ) {

		cout << n ;

		return 0 ;
	}

	sort( a + 1 , a + 1 + n ) ;

	for( int i = 1 ; i <= n ; i++ ) {

		b[i] = sum - a[i] ;

	}


	while( f2 == true ) {

		sum2 = sum - k ;

		long long *t = upper_bound( a + 1 , a + 1 + n , sum2 ) ;

		long long p = t - a ;


		p-- ;

		for ( int i = p ; i >= 1 ; i-- ) {

			long long tb = b[i] - k ;

			if( m2 + tb > m ) {
				break ;
			}

			tans++ ;
			m2 += tb ;

		}

		if( k == 0 ) {

			if( tans == p ) {
				ans = max( ans , tans ) ;
				k-- ;
				tans = 0 ;
				sum2 = 0 ;
				m2 = 0 ;
			}
			else{
				ans = max( ans , tans ) ;
				tans = 0 ;
				sum2 = 0 ;
				m2 = 0 ;
				k++ ;
			}

		}
		else if( k > 0 ) {

			if( tans == p ) {

				ans = max( ans , tans ) ;
				f2 = false ;

			} else {
				ans = max( ans , tans ) ;
				tans = 0 ;
				sum2 = 0 ;
				m2 = 0 ;
				k++ ;
			}
		}
		else if( k < 0 ) {
			
			if( tans < ans ) {
				f2 = false ;
			}
			else{
				
				ans = max( ans , tans ) ;
				k-- ;
				tans = 0 ;
				sum2 = 0 ;
				m2 = 0 ;
				
			}
			
		}

	}
	
	if( ans == 0 ) {
		cout << "1" ;
		
	}
	else{
		cout << ans ;
	}
	


	fclose(stdin);
	fclose(stdout);
	
	return 0 ;

}

