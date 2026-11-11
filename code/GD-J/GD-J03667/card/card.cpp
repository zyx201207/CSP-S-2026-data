#include <iostream>
#include <map>
#include <cstring> 
using namespace std;
int a[500005];
int ans[300005];
map <int , int> where;
//数值映射下标 
map <int , int> what;
//下标映射数值 
bool vis[500005];
int main()
{
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	long long cnt = 0;
	for (int t = 1; t <= n-1 ; t ++)
	{
		for (int i = t; i <= n; i++)
		{
			if (where[a[i]] == 0)
			{
				what[++cnt] = a[i];
				where[a[i]] = cnt;
				vis[a[i]] = true;
			}
			else 
			{
				for (int j = where[a[i]] ; j < i; j++)
				{
					what[j] = 0;
					vis[what[i]] = false;
				}
				what[++cnt] = a[i];
				where[a[i]] = cnt;
				vis[a[i]] = true;
			}
//		memset(vis , 0 , sizeof(vis));
			
		}
		for (int j = 1; j <= m; j ++)
		{
			if (vis[j])
			{
				ans[j] ++;
			}
		}
	}
	
	for (int i = 1; i <= m; i ++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
