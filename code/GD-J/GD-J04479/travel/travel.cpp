#include<bits/stdc++.h>
using namespace std ;
string c1 , s1 , c2 , s2 , p1 , p2 ;
char h1 , h2 ;
bool f1 = 0 , f2 = 0 , f3 = 0 ;
int main(){
	freopen( "travel.in" , "r" , stdin ) ;
	freopen( "travel.out" , "w" , stdout ) ;
	cin >> c1 >> s1 >> c2 >> s2 ;
	if( c1 == c2 ){
		cout << 1 ;
		f1 = 1 ;
	}else{
		cout << 0 ;
	}
	for( int i = 0 ; i < s1.size() ; i++ ){
		if( s1[i] >= '0' && s1[i] <= '9' ){
			p1 += s1[i] ;
			p2 += s2[i] ;
		}else{
			h1 = s1[i] ;
			h2 = s2[i] ;
		}
	}
	if( f1 == 1 && p1 == p2 ){
		cout << 1 ;
		f2 = 1 ;
	}else{
		cout << 0 ;
	}
	if( f2 == 1 && ( h1 >= 'A' && h1 <= 'C' && h2 >= 'A' && h2 <= 'C' ) || ( h1 >= 'D' && h1 <= 'F' && h2 >= 'D' && h2 <= 'F' ) ){
		f3 = 1 ;
		cout << 1 ;
	}else{
		cout << 0 ;
	}
	if( f3 == 1 && abs( h1 - h2 ) == 1 ){
		cout << 1 ;
	}else{
		cout << 0 ;
	}
	return 0 ;
}
