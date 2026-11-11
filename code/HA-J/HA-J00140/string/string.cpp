#include<bits/stdc++.h>
using namespace std ;
long long n , g , e = 0 , ans;
string a , b; 
int main(){
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ; 
	cin >> n ;
	for (int i = 1 ; i <= n ; i++){
		int q ;
		cin >> q ;
		g+=q;
		string h ;
		cin >> h ;
		for (int j = 1 ; j <= q ; j++)
		     a+= h ;
	}
	if(g % 2 == 1){
		int s = (g-1)/2 , j = g-1 ;
		for (int i = 0 ; i < s; i++){
			if(a[i] != a[j]) ans++ ;
			j-- ;
		}
		cout << ans ;
	}else {
		int s = g/2 - 1 , j = g - 1;
		for (int i = 0 ; i <= s ; i++){
			if(a[i] != a[j]) ans++ ;
			j-- ;
		}
		cout << ans ;
	}
	return 0 ; 
} 
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
