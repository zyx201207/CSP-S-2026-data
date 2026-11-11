#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n , m;
int a[N];
bool vis[N];
int main()
{
	freopen("and.in" , "r" , stdin) , freopen("and.out" , "w" , stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)cin>>a[i] , vis[i] = 1;
	for(int j = 30;j >= 1;j--)
	{
		int gs = 0;
		for(int i = 1;i <= n;i++)
		{
			if(vis[i] == 0)continue;
			int ys = 1 << (j - 1);
			if((ys & a[i]) != 0)
			{
				gs++;
			}
		}
		if(gs >= m)
		{
			for(int i = 1;i <= n;i++)
			{
				if(vis[i] == 0)continue;
				int ys = 1 << (j - 1);
				if((ys & a[i]) == 0)vis[i] = 0;
			}
		}
	}
	int ans = -1 , cs = 0;
	for(int i = 1;i <= n;i++)
	{
		if(vis[i] == 1 && cs + 1 <= m)
		{
			cs++;
			if(ans == -1)ans = a[i];
			else ans &= a[i];
		}
	}
	cout<<ans;
	return 0;
}
