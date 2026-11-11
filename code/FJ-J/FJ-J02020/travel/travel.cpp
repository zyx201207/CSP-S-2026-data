#include<bits/stdc++.h>
using namespace std ;


int main() {
	freopen("travel.in" ,"r" ,stdin ) ;
	freopen("travel.out" ,"w" ,stdout ) ;
	string a ,b ,c, d ;
	cin >> a >> b >> c >> d; 
	int a1 ,b1 ,c1 ,d1 ;
	a1 = a[0] * 10 + a[1] ;
	b1 = b[0] * 10 + b[1] ;
	c1 = c[0] * 10 + c[1] ;
	d1 = d[0] * 10 + d[1] ;
	if(a1 != c1 ) cout << "0000" ;
	else if(b1 != d1 ) {
		cout << 1000 ;
	}
	else if((b[2] - 'A' <= 2 && d[2] - 'A' > 2 ) || (b[2] - 'A' > 2 && d[2] - 'A' <= 2 )) {
		cout << 1100 ;
	}
	else if(abs(b[2] - d[2]) != 1 ) {
		cout << 1110 ;
	}
	else cout << 1111 ;
	
	
	
	
	return 0 ;
}
