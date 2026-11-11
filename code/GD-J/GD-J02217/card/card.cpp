#include<iostream>
using namespace std;
int n , m , a[500005] , as[300005];
int main(){
	freopen( "card.in" , "r" , stdin );
	freopen( "card.out" , "w" , stdout );
	cin >> n >> m;
	for( int i = 1 ; i <= n ; i++ ){
		cin >> a[i];
	}
	for( int i = 1 ; i <= n ; i++ ){
		bool f[300005] = {};
		int b[300005] = {};
		int ams = 1;
		for( int j = i ; j <= n ; j++ ){
			if( f[a[j]] == 0 ){
				b[ams] = a[j];
				f[a[j]] = 1;
				ams++;
			}
			else{
				int ans = j-1;
				while( b[ans] != a[j] ){
					b[ans] = 0;
					ams--;
					ans--;
				}
			}
		}
		for( int j = 1 ; j < ams ; j++ ){
			as[b[j]]++;
		}
	}
	for( int i = 1 ; i <= m ; i++ ){
		cout << as[i] << " "; 
	}
	return 0;
} 
