#include <bits/stdc++.h> 
using namespace std ;
int a[200005] , n , m , book[200005] , ans ;
void dfs(int now , int k)
{
	//if (now > 1) cout << k << " " ;
	if (now == m){
		ans = max(ans , k) ;
		return ;
	}
	for (int i = 1 ; i <= n ; i++){
		if (!(book[i])) {
			book[i] = 1 ;
			dfs(now + 1 , k & a[i]) ;
			book[i] = 0 ;
		}
	}
	return ;
}
int main()
{
	freopen("and.in" , "r" , stdin) ;
	freopen("and.out" , "w" , stdout) ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; i++) cin >> a[i] ;
	for (int i = 1 ; i <= n ; i++) {
		book[i] = 1 ;
		dfs(1 , a[i]) ;
		book[i] = 0 ;
	}
	cout << ans ;
	return 0 ;
}
