#include <bits/stdc++.h>
using namespace std ;
int n , m , ans[500005] , a[500005] ;
bool vis[500005] , f[500005] ;
int main()
{
	freopen("card.in" , "r" , stdin) ;
	freopen("card.out" , "w" , stdout) ;
	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i] ;
	for(int i = 1 ; i <= n ; i ++)
	{
		memset(vis , 0 , sizeof(vis)) ;
		memset(f , 0 , sizeof(f)) ;
		stack<int> q ;
		for(int j = i ; j <= n ; j ++)
		{
			if(!vis[a[j]]) q.push(a[j]) , vis[a[j]] = 1 ;
			else
			{
				while(!q.empty())
				{
					if(q.top() == a[j])
					{
						vis[q.top()] = 0 ;
						q.pop() ;
						break ;
					}
					vis[q.top()] = 0 ;
					q.pop() ;
				}
				q.push(a[j]) ;
				vis[a[j]] = 1 ;
			}
		}
		for(int j = 1 ; j <= n ; j ++)
		{
			if(vis[a[j]] && !f[a[j]]) ans[a[j]] ++ , f[a[j]] = 1 ;
		}
	}
	for(int i = 1 ; i <= m ; i ++) cout << ans[i] << " " ;
	return 0 ;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
