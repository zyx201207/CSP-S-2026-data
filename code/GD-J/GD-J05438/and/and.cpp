#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int a[200005];
bool vis[200005];
int n , m;
int sum;
void dfs(int x , int ans , int cnt)
{
	if(vis[x] == true) return ;
	else vis[x] = true;
	if(cnt == m)
	{
		sum = max(sum , ans);
		vis[x] = false;
		return ;
	}
	for(int i = 1; i <= n; i++)
	{
		int w = ans;
		ans &= a[i];
		dfs(i , ans , cnt + 1);
		ans = w;
	}
	vis[x] = false;
}
bool cmp(int x , int y)
{
	return x > y;
}
int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	long long maxn = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxn = max(maxn , a[i] * 1ll);
	}
	if(m == 1)
	{
		cout << maxn;
		return 0;
	}
	if(m == 2)
	{
		maxn = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				if(i == j)
				{
					continue;
				} 
				maxn = max(maxn , a[i] & a[j] * 1ll);
			}
		}
		cout << maxn;
		return 0;
	}
	if(m == n)
	{
		long long ans = a[1];
		for(int i = 2; i <= n; i++)
		{
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	if(n <= 20)
	{
		for(int i = 1; i <= n; i++)
		{
			memset(vis , false , sizeof(vis));
			dfs(i , a[i] , 1);
		}
		cout << sum;
		return 0;
	}
	sort(a + 1 , a + n + 1 , cmp);
	cout << a[m];
	return 0;
}
