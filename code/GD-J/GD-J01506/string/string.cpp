#include<bits/stdc++.h>
#define FOR(i , a , b) for(int i = (a) ; i <= (int)(b) ; ++ i)
using namespace std ;
using ll = long long ; 
const int N = 2e5 + 10 ;
ll a[N] ;
char c[N] ; 
signed main(){
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;  
	ios::sync_with_stdio(false) , cin.tie(0) ; 
	int n ; cin >> n ;
	FOR(i , 1 , n) cin >> a[i] >> c[i] ;
	ll  ans = 0 ;
	int l = 1 , r = n ; 
	while(l <= r){
		if(c[l] == c[r]){
			if(a[l] > a[r]) a[l] -= a[r] , r -- ; 
			else if(a[l] < a[r]) a[r] -= a[l] , l ++ ;  
			else l ++ , r -- ;
		}else{
			if(a[l] > a[r]) ans += a[r] , a[l] -= a[r] , r -- ;
			else if(a[l] < a[r]) ans += a[l] , a[r] -= a[l] , l ++ ; 
			else ans += a[l] , l ++ , r -- ; 
		}
	}
	//FOR(i , 1 , n) cout << a[i] << " " ; 
	return cout << ans , 0 ; 
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
