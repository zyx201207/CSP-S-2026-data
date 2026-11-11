#include <bits/stdc++.h>

using namespace std ;

int main ()
{
	freopen("card.in" , "r" , stdin) ;
	freopen("card.out" , "w" , stdout) ;
	int n , m , x , a[50000000] ;
	string zdx = "" ;
	for(int i = 1;i <= n;i ++) {
		cin >> x ;
		bool z[5000000] ;
		int ans = 0 , ji ;
		char zzz = x + '0' ; 
		zdx.push_back (zzz) ;
		for(int c = 0;c < zdx.size() - 1;c ++){
			if(zdx[c] == zzz) {
				ans ++ ;
				ji = c ;
			}
		}
		if(ans == 1) {
			for(int i = ji;i < zdx.size();i ++){
				zdx[i] = ' ' ;
			}
		}
		for(int i = 1;i <= n;i ++){
			z[i] = false ;
		}
		for(int i = 0;i < zdx.size();i ++) {
			z[zdx[i] - '0'] = true ;
		}
		for(int i = 1;i <= n;i ++) {
			if(z[i]) a[i] ++ ;
		}
	}
	for(int i = 1;i <= n;i ++) cout << a[i] <<  " " ;
	return 0 ;
}
