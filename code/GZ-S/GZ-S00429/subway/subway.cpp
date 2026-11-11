//GZ-S00429   李培昊   遵义四中
#include <bits/stdc++.h>
using namespace std;

long long c , n , m , d , q ;

long long w , k , a , t ;
long long x1 , y1 ;
long long sum[100005] ;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c>>n>>m>>d>>q ;
	
	for( int i = 1 ; i <= m ; i++ ) {
		cin >> w ;
	}
	
	for( int i = 1 ; i <= n ; i++ ) {
		cin >> k ;
		for( int j = 1 ; j <= k ; j++ ) {
			cin >> a >> t ;
			sum[i] += a ;
			sum[i] += t ;
		}
	}
	
	for( int i = 1 ; i <= q ; i++ ) {
		cin >> x1 >> y1 ;
	}
	
	for( int i = 1 ; i <= q ; i++ ) {
		
		cout << sum[i] << "\n" ;
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0 ;
}


