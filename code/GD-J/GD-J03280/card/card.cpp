#include <bits/stdc++.h>
using namespace std ;

int n, m ;

int a[500086] ;
stack <int> stk ;

int main (){
	ios_base::sync_with_stdio(0) ;
	cin.tie();
	cout.tie();
	
	freopen("card.in", "r", stdin) ;
	freopen("card.out", "w", stdout) ;	
	
	cin >> n >> m ;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i] ;
	}
	return 0 ;
}
