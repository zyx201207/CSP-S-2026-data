#include<bits/stdc++.h>
#define FOR(i , a , b) for(int i = (a) ; i <= (int)(b) ; ++ i)
using namespace std ;
signed main(){
	freopen("hub.in","r",stdin) ;
	freopen("hub.out","w",stdout) ; 
	ios::sync_with_stdio(false) , cin.tie(0) ; 
	int c , t ; cin >> c >> t ;
	while(t --){
		int n , k ; cin >> n >> k ;
		FOR(i , 1 , n - 1){
			int x , y ; cin >> x >> y ;
		}
		if(n == k){
			cout << 0 << "\n" ;
			continue ; 
		} 
		if(n <= 5 && k >= 2){
			cout << 1 << "\n" ; 
			continue ;
		}
		if(n <= 5 && k == 1){
			cout << 2 << "\n" ;
			continue ;
		}
		if(n == 6 && k == 1){
			cout << 2 << "\n" ;
			continue ; 
		}
		if(n == 6 && k >= 2){
			cout << 1 << "\n" ; 
			continue ; 
		}  
		if(n >= 5 && n - k >= 3) cout << 2 << "\n" ;
		else cout << 1 << "\n" ; 
	}
	return 0 ; 
}
/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8

6 5
1 2
2 5
4 5
5 3
3 6

9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9
*/
