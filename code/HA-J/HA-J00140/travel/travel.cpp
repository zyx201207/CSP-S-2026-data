#include<bits/stdc++.h>
using namespace std ;
char a[100] , b[100] , c[100] , d[100]  ;
bool q = 0 ;
int main(){
	freopen("travel.in","r",stdin) ;
	freopen("travel.out","w",stdout) ;
	cin >> a >> b >> c >> d ;
	if(a[0] == c[0] && a[1] == c[1]){
		q = 1;
		cout << 1 ;
	}
	else cout << 0 ;
	if(q == 1){
	   if(b[0] == d[0] && b[1] == d[1]){
	   cout << 1 ;
	}
	else {
		q = 0 ;
		cout << 0 ; 
	}
	}else cout << 0 ;
	if( q == 1){
	   if((b[2]<='C' && d[2] <= 'C') || (b[2]>= 'D' && d[2] >= 'D')){
		  cout << 1 ;
	   }else {
	   	  q = 0 ;
	   	  cout << 0 ;
	   }
	}else cout << 0 ;
	if(q == 1){
	   if((b[2] == 'A' && d[2] == 'B') || (b[2] == 'B' && d[2] == 'A') || (b[2] == 'C' && d[2] == 'B')||(b[2] == 'B' && d[2] == 'C')||(b[2] == 'D' && d[2] == 'F')||(b[2] == 'F' && d[2] == 'D'))cout << 1 ;
	   else cout << 0 ;
	} else cout << 0 ;
	
	return 0 ; 
} 
