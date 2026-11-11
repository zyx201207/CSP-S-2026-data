#include <bits/stdc++.h>
using namespace std;
int a[200005],n,m,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(m== 1)
	{
		for(int i = 1;i <= n;i++) ans = max(ans,a[i]);
		
	}
	if(m==2)
	{
		for(int i = 1;i <= n-1;i++)
		{
			for(int j = i;j <= n;j++)
			{
				ans = max(ans,(a[i] & a[j]));
			} 
		}
	}
	if(m == n)
	{
		ans = (a[1] & a[2]);
		for(int i = 3;i <= n;i++)
		{
			ans = (ans & a[i]);
		}
	}
	if(m == (n-1))
	{
		sort(a+1,a+n+1);
		ans = (a[2] & a[3]);
		for(int i = 4;i <= n;i++) ans = (ans & a[i]);
	}
	
	cout << ans;
	return 0;
} 
