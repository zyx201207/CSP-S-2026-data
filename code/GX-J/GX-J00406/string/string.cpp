#include <bits/stdc++.h>
using namespace std ;
int main()
{
	freopen("string.in" , "r" , stdin ) ;
	freopen("string.out" , "w" ,stdout ) ;
	long long n ;
	cin >> n ;
	long long a ;
	char c ;
	string s ;
	for( int i =1 ; i <= n ; i++ ){
		cin >> a ;
		cin >> c ;
		for(int j = 1 ; j <= a ; j++ ){
			s += c ;
		}
	}
	string bz ;
	for( int i = s.size() ; i>= 1 ; i-- ){
		bz += s[i] ;
	}
	int bq = 0 ;
	if( s = bz)
		cout << "0" ;
	else{
		for(int i = 1 ;i <= s.size() ; i++ ){
			if( s[i] != bz[i] )
				bq++ ;
		}
	}
	cout << bq ;
	return 0 ;
}
