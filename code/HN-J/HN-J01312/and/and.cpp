#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 5 ;
int n , m , a[N] , x[N] , ans ;
void dfs(int step , int sum , int cnt)
{
	if(step > n)
	{
		if(cnt == m) ans = max(ans , sum) ;
		return ;
	}
	dfs(step + 1 , (sum & a[step]) , cnt + 1) ;
	dfs(step + 1 , sum , cnt) ;
}
bool cmp(int x , int y)
{
	return x > y ;
}
signed main()
{
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	freopen("and.in" , "r" , stdin) ;
	freopen("and.out" , "w" , stdout) ;
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i] ;
	if(m == 1)
	{
		int ans = 0 ;
		for(int i = 1 ; i <= n ; i ++) ans = max(ans , a[i]) ;
		cout << ans ;
		return 0 ;
	}
	if(m == 2)
	{
		int ans = 0 ;
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = i + 1 ; j <= n ; j ++) ans = max(ans , (a[i] & a[j])) ;
		}
		cout << ans ;
		return 0 ;
	}
	if(m == n)
	{
		int ans = a[1] ;
		for(int i = 2 ; i <= n ; i ++) ans = (ans & a[i]) ;
		cout << ans ;
		return 0 ;
	}
	if(n <= 20)
	{
		dfs(1 , 1 , 0) ;
		cout << ans ;
		return 0 ;
	}
	int maxn = 0 ;
	for(int i = 1 ; i <= n ; i ++) maxn = max(maxn , a[i]) ;
	if(maxn <= 4)
	{
		for(int i = 1 ; i <= n ; i ++) x[a[i]] ++ ;
		if(x[4] >= m) cout << 4 ;
		else if(x[3] >= m) cout << 3 ;
		else if(x[2] >= m || x[2] + x[3] >= m) cout << 2 ;
		else if(x[1] >= m) cout << 1 ;
		else cout << 0 ;
		return 0 ;
	}
	sort(a + 1 , a + n + 1 , cmp) ;
	int ans = a[1] ;
	for(int i = 2 ; i <= m ; i ++) ans = (ans & a[i]) ;
	cout << ans ;
	return 0 ;
}

