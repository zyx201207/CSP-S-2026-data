//GZ-J00502 ³ÂÜÆÝæ 
#include <bits/stdc++.h>
using namespace std ;
string a,b,c,d ;
string s ;
int f ;
int main(){
	freopen("travel.in" , "r" , stdin) ;
	freopen("travel.out" , "w" , stdout) ;
	cin >> a >> b >> c >> d ;
	if(a == c && a != "01" && a != "16" && c != "01" && c != "16"){
		cout << 1 ; 
		f = 1 ;
	}
	else{
		cout << 0 ;
		f = 0 ;
	}
	if(f == 1 && b[0] == d[0] && b[1] == d[1]){
		cout << 1 ;
		f = 1 ;
	}
	else{
		cout << 0 ;
		f = 0 ;
	}
	if(f == 1 && ((b[2] <= 'C' && d[2] <= 'C') || (b[2] <= 'F' && b[2] > 'C' && d[2] <= 'F' && d[2] > 'C'))){
		cout << 1 ;
		f = 1 ;
	}

	else{
		cout << 0 ;
		f = 0 ;
	}
	if(f == 1 && (int(b[2])-int(d[2]) == 1 || int(d[2])-int(b[2]) == 1)){
		cout << 1 ;
	}
	else{
		cout << 0 ;
	}
	return 0 ;
}
