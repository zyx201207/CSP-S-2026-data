//GZ-J00502 ³ÂÜÆÝæ 
#include <bits/stdc++.h>
using namespace std ;
int n,m ;
const int N = 5e5+10 ;
int a[N] ;
int main(){
	freopen("card.in" , "r" , stdin) ;
	freopen("card.out" , "w" , stdout) ;
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] ;
	}
	cout << n << ' ' << m << ' ' << a[1] ;
	return 0 ;
}
