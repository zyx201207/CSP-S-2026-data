#include<bits/stdc++.h> 
using namespace std;
int a[100000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	int n,d;
	for(int i=1;i<=t;i++)
	{
		cin >> n >> d;
		if(n > 100)
		{
			for(int i=1;i<=100;i++)
			{
				cin >> a[i];
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				cin >> a[i];
			}
		}
		int flag = 1;
		if(n > 100)
		{
			for(int i=1;i<=100;i++)
			{
				if(i>1)
				{
					if(a[i] == a[i-1] + 1)
					{
					
					}
					else
					{
						flag = 0;
						break;
					}
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(i>1)
				{
					if(a[i] == a[i-1] + 1)
					{
					
					}
					else
					{
						flag = 0;
						break;
					}
				}
			}
		}
		if(flag == 1 && n > 2 * d - 1)
		{
			cout << n - (2 * d - 1) << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	return 0;
}
