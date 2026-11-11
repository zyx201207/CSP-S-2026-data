#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
const long long INF = 500005;
long long ap[ MAXN ];
long long n , m , ans;
int main(){
	freopen( "crystal.in" , "r" , stdin );
	freopen( "crystal.out" , "w" , stdout );
	cin >> n >> m;
	for( int i = 1 ; i <= n ; i ++ ){
		cin >> ap[ i ];
	}
	sort( ap + 1 , ap + n + 1 );
	for( int i = 1 ; i <= n ; i++ ){
		ap[ i ] += ap[ i - 1 ];
	}
	int j = 1 , sum = 0;
	long long len = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		sum = 0;
		while( sum <= m && j <= n ){
			j++;
			sum = ( ap[ j ] - ap[ j - 1 ]  ) * ( j - i + 1 ) - ( ap[ j ] - ap[ i - 1 ] );
			if( sum > m ){
				j--;
			}
			len = j - i + 1;
			ans = max( ans , len );
		}
	}
	cout << ans;
	return 0;
} 
