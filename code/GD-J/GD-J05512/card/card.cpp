#include<bits/stdc++.h>    
using namespace std ;
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n , m , t = 0 ;
	cin >> n >> m ;
	int a [ n ] ;
	for ( int i = 1 ; i <= n ; i ++ ){
		cin >> a [ i ] ;
	}
	for ( int i = 1 ; i <= n ; i ++ ){
		if ( a [ i ] == m ){
			t ++ ;
		}
	}
	cout << n << " " << t << " " << m ;
	return 0 ;
}
