#include <bits/stdc++.h> 
using namespace std ;
int m[20] , ok1 , ok2 ;
int main()
{
	string a , b , c , d ;
	freopen("travel.in" , "r" , stdin) ;
	freopen("travel.out" , "w" , stdout) ;
	cin >> a >> b >> c >> d ;
	char b1 , d1 ;
	b1 = b[2] , d1 = d[2] ;
	if (a[0] == c[0] && a[1] == c[1]) cout << "1" ;
		else cout << "0" ;
	if (b[0] == d[0] && b[1] == d[1]) cout << "1" ;
		else cout << "0" ;
	//if (b[0] == d[0] && (b[1] == d[1] && !((b[2] == "C" && d[2] == "D") || (b[2] == "D" && d[2] == "C"))) cout << "1" ;
		//else cout << "0" ;
//	if (b[0] == d[0] && b[1] == d[1] && (abs(b[2] - d[2]) == 1 && (!((b[2] == "C" && d[2] == "D") || (b[2] == "D" && d[2] == "C")))) cout << "1" ;
//		else cout << "0" ;
	if (b[0] == d[0] && b[1] == d[1]){
		if (b1 == 'D'){
			if(d1 =='F') ok1 = 1 ;
		}
		else if (d1 == 'D'){
			if (b1 == 'F') ok1 = 1 ;
		}
		else ok1 = 1 ;
	}
	if (ok1) cout << "1" ;
	else cout << "0" ;
	if (ok1){
		if (abs(b1 - d1) == 1) ok2 = 1 ;
	}
	if (ok2) cout << "1" ;
	else cout << "0" ;
	//else cout << "0" ;
	//else cout << "0" ;
	return 0 ;
}
