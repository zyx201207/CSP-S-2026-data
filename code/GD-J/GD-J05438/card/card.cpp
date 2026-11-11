#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[500005];
int ans[500005];
bool vis[500005];
int main()
{
	freopen("card.in" , "r" , stdin);
	dreopen("card.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	bool t = true;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i]; 
	}
	for(int i = 2; i <= n; i++)
	{
		if(a[i] < a[i - 1])
		{
			t = false;
			break;
		}
	}
	if(t == true)
	{
		for(int i = n; i >= 1; i--)
		{
			if(vis[a[i]] == false)
			{
				ans[a[i]] += i;
				vis[a[i]] = true;
			}
		}
		for(int i = 1; i <= m; i++)
		{
			cout << ans[i] << " ";
		}
		return 0;
	}
	return 0;
}
