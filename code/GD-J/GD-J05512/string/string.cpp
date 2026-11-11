#include<bits/stdc++.h>
using namespace std ;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n , t = 0 , m ;
	cin >> n ;
	int s [ n ] , z [ n ] ;
	for ( int i = 1 ; i <= n ; i ++ ){
		cin >> s [ i ] >> z [ i ] ;
		if ( z [ i ] == z [ i - 1 ] ){
			t = 0 ;
		}
		else {
			t ++ ;
		}
		if ( s [ i ] == s [ i + 1 ] && z [ n / 2 ] == z [ 1 ] && z [ n / 2 + 1 ] == z [ n ] ){
			for ( int j = 1 ; j <= i / 2 ; j ++ ){
				m += s [ j ] ;
			}
		}
		else {
			m = 0 ;
		}
	}
	if ( t == 0 ){
		cout << t ;
	}
	else if ( m != 0 ){
		cout << m ;
		
	} 
	else {
		cout << "0" ;
	}
	return 0 ;
}
