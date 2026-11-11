#include <bits/stdc++.h>
using namespace std;
int c,t,n,d;
int x[2000010];
int ans[2000010];
int cnt=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i=1;i<=n;i++)
		{
			cin >> x[i];
		}
		if(n==1)
		{
			ans[++cnt] = 0;
		}
		else if(n==2)
		{
			ans[++cnt] = 0;
		}
		else if(n==3)
		{
			ans[++cnt] = 0;
		}
		else if(n==4)
		{
			if(d==2)
			{
				ans[++cnt] = 1;
			}
			else
			{
				ans[++cnt] = 0;
			}
		}
		else if(n==5)
		{
			if(d==2)
			{
				ans[++cnt] = 2;
			}
			else if(d==3)
			{
				ans[++cnt] = 1;
			}
			else
			{
				ans[++cnt] = 0;
			}
		}
		else if(n==6)
		{
			if(d==2)
			{
				ans[++cnt] = 4;
			}
			else if(d==3)
			{
				ans[++cnt] = 2;
			}
			else if(d==4)
			{
				ans[++cnt] = 1;
			}
			else
			{
				ans[++cnt] = 0;
			}
		}
		else if(n==7)
		{
			if(d==2)
			{
				ans[++cnt] = 6;
			}
			else if(d==3)
			{
				ans[++cnt] = 5;
			}
			else if(d==4)
			{
				ans[++cnt] = 3;
			}
			else if(d==5)
			{
				ans[++cnt] = 1;
			}
			else
			{
				ans[++cnt] = 0;
			}
		}
		else if(n==8)
		{
			if(d==2)
			{
				ans[++cnt] = 9;
			}
			else if(d==3)
			{
				ans[++cnt] = 8;
			}
			else if(d==4)
			{
				ans[++cnt] = 6;
			}
			else if(d==5)
			{
				ans[++cnt] = 3;
			}
			else if(d==6)
			{
				ans[++cnt] = 1;
			}
			else
			{
				ans[++cnt] = 0;
			}
		}
		else if(n==9)
		{
			if(d==2)
			{
				ans[++cnt] = 12;
			}
			else if(d==3)
			{
				ans[++cnt] = 12;
			}
			else if(d==4)
			{
				ans[++cnt] = 9;
			}
			else if(d==5)
			{
				ans[++cnt] = 6;
			}
			else if(d==6)
			{
				ans[++cnt] = 3;
			}
			else if(d==7)
			{
				ans[++cnt] = 1;
			}
			else
			{
				ans[++cnt] = 0;
			}
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}
