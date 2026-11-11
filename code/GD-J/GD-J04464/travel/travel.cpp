#include <bits/stdc++.h>

using namespace std ;

int main ()
{
	freopen("travel.in" , "r" , stdin) ;
	freopen("travel.out" , "w" , stdout) ;
	string a , b , c , d , zzz , xxx ;
	cin >> a >> b >> c >> d ;
	if(a == c) cout << 1 ;
	else { 
		  cout << "0000" ;
		  return 0 ;
	}
	zzz.push_back(b[0]) ;
	zzz.push_back(b[1]) ;
	xxx.push_back(d[0]) ;
	xxx.push_back(d[1]) ;
	if(zzz == xxx) cout << 1 ;
	else {
		cout << "000" ;
		return 0 ;
	}
	if((b[2] <= 'C' && b[2] >= 'A' ) && (d[2] <= 'C' && d[2] >= 'A') && b[2] != d[2])  cout << 1 ;
	else if ((b[2] == 'D' || b[2] == 'F') && (d[2] == 'D' || d[2] == 'F') && d[2] != b[2]) {
		cout << "11" ;
		return 0 ;
	}
	else {
		cout << "00" ;
		return 0 ;
	}
	if((b[2] == 'A' && d[2] == 'B') || (b[2] == 'B' && d[2] == 'C') || (d[2] == 'A' && b[2] == 'B') || (d[2] == 'B' && b[2] == 'C')) cout << 1 ;
	else cout << 0 ;
	return 0 ;
 } 
