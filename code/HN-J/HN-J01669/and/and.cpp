#include <bits/stdc++.h>
using namespace std ;
#define int long long
int n , m , ans , a[200005] , vis[200005] ;
void dfs(int num , int s)
{
	if(num == m + 1)
	{
		ans = max(s , ans) ;
		return ;
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		if(!vis[i])
		{
			vis[i] = 1 ;
			dfs(num + 1 , s & a[i]) ;
			vis[i] = 0 ;
		}
	}
	return ;
}
signed main()
{
	freopen("and.in" , "r" , stdin) ;
	freopen("and.out" , "w" , stdout) ;
	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i] ;
	sort(a + 1 , a + n + 1) ;
	if(m == 1)
	{
		cout << a[n] ;
		return 0 ;
	}
	if(m == 2)
	{
		int maxn = 0 ;
		for(int i = 1 ; i < n ; i ++)
		{
			maxn = max(maxn , a[n] & a[i]) ;
		}
		cout << maxn ;
		return 0 ;
	}
	if(m == n - 1)
	{
		int g = a[1] , maxn = 0 ;
		for(int i = 2 ; i <= n ; i ++)
		{
			g = g & a[i] ;
		}
		for(int i = 1 ; i <= n ; i ++)
		{
			maxn = max(maxn , g | a[i]) ;
		}
		cout << maxn ;
		return 0 ;
	}
	if(n <= 20)
	{
		for(int i = 1 ; i <= n ; i ++) vis[i] = 1 , dfs(2 , a[i]) , vis[i] = 0 ;
		cout << ans ;
	}
	else cout << a[n - m + 1] ;
	return 0 ;
}
