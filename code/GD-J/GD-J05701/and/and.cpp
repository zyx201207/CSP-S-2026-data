#include <iostream>
using namespace std ;
const int N = 2e5 + 10 ;
long long a[N] ;
bool vis[N] = {0} ;
long long ans = -1 ;
int n , m ;
void dfs(int deep , long long sum , int s)
{
	if (deep == m+1)
	{
		ans = max(ans , sum) ;
		return ;
	}
	for (int i = s+1 ; i <= n ; i++)
	{
		if (!vis[i])
		{
			vis[i] = true ;
			long long num = sum & a[i] ;
			dfs(deep + 1, num , i) ;
			vis[i] = false ;
		}
		
	}
}
int main ()
{
	freopen("and.in" , "r" , stdin) ;
	freopen("and.out" , "w" , stdout) ;
	cin >> n >> m ;
	for (int i = 1 ; i<= n ; i++)
	{
		cin >> a[i] ;
	}
	for (int i = 1 ; i <= n ; i++)
	{
		dfs(2 , a[i] , i) ;
	}
	cout << ans ;
	return 0 ;
}
