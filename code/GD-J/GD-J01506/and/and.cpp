#include<bits/stdc++.h>
#define FOR(i , a , b) for(int i = (a) ; i <= (int)(b) ; ++ i)
using namespace std ;
const int N = 2e5 + 10 ;
int a[N] , b[N] ;
int p[35] ; 
bool cmp(int a , int b){ return a >= b ; }
signed main(){
	freopen("and.in","r",stdin) ; 
	freopen("ans.out","w",stdout) ;
	ios::sync_with_stdio(false) , cin.tie(0) ;
	int n , m ; cin >> n >> m ; 
	FOR(i , 1 , n) cin >> a[i] ;  
	sort(a + 1 , a + n + 1 , cmp) ; 
	FOR(i , 1 , n) b[i] = log2(a[i]) + 1 ;
	p[0] = 1 ; 
	FOR(i , 1 , 32) p[i] = p[i - 1] * 2 ;
	int ans1 = a[1] ;
	FOR(i , 1  , m) ans1 &= a[i] ;  
	int k = b[1] - 1 ;
	int ans = 0 ;  
	//cout << p[k] << "\n" ; 
	//FOR(i , 1 , n) if(a[i] >= p[7]) cout << a[i] << "\n" ; 
	//cout << n << " " << m << "\n" ;
	//FOR(i , 1 , n) cout << a[i] << " " ;  
	while(k){
		int cnt = 0 ; 
		FOR(i , 1 , n){
			if(a[i] >= p[k]){ a[i] -= p[k] , cnt ++ ; } 
			//else break ; 
		} 
		//FOR(i , 1 , n) cout << a[i] << " " ;
		//cout << cnt << " " << p[k] << "\n" ;  
		if(cnt >= m) ans += p[k] ;
		k -- ; 
	} 
	cout << max(ans,ans1) ;
	return 0 ; 
}
/*

*/
