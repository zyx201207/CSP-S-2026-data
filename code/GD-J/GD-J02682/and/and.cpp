#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n , m , a[200005] , ans = 1;
bool vis[200005];
int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n;
	cin >> m;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	memset(vis , 0 , sizeof(vis));
	for(int i = 1 ; i <= n ; i++)
	{
		ans = max(ans , a[i]);
	}
	for(int i = 2 ; i <= m ; i++)
	{
		int cnt = 0;
		for(int j = 1 ; j <= n ; j++)
		{
			if(vis[cnt] == 0)
			{
				if((a[j] & ans) > ans)
				{
					ans = a[j] & ans;
					cnt = j;
				}
			}	
		}
		vis[cnt] = 1;
	}
	cout << ans;
	return 0;
}

