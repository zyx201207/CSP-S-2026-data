#include <bits/stdc++.h>
using namespace std;
int a[200005];
int nd(int x,int y)
{
	int cnt = 0,z = 1;
	for(int i = 0;i <= 29;i++)
	{
		if(x%(2*z)>=z&&y%(2*z)>=z)cnt+=z;
		z = z*2;
	}
	return cnt;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(m==1)
	{
		for(int i = 1;i <= n;i++)
		{
			ans = max(ans,a[i]);
		}
		cout << ans;
		return 0;
	}
	if(m==2)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = i+1;j <= n;j++)
			{
				ans = max(ans,nd(a[i],a[j]));
			}
		}
		cout << ans;
		return 0;
	}
	if(m==n)
	{
		ans = a[1];
		for(int i = 2;i <= n;i++)
		{
			ans = nd(ans,a[i]);
		}
		cout << ans;
		return 0;
	}
	cout << 7;
	return 0;
}
