#include <bits/stdc++.h>
using namespace std;
int n , a[20000005] , m , dis[2000005] , vis[2000005] , maxn = -1e9;
/*void dfs(int step , int sum)
{
	if(step > m)
	{
		maxn = max(maxn , sum);
		return;
	} 
	for(int i = 1 ; i <= n ; i++)
	{
		if(vis[i])continue;
		vis[i] = 1;
		dfs(step + 1 , sum & a[i]);
		vis[i] = 0;
	}
}*/
int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
	{ 
		cin >> a[i];
		if(m == 1)maxn = max(maxn , a[i]);
	}
	//dfs(0 , a[1]);
	if(m == 2)
	{
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = i + 1 ; j <= n ; j++)
			{
				maxn = max(maxn , (a[i] & a[j]));
			}
		}
	}
	cout << maxn;
	return 0;
} 
