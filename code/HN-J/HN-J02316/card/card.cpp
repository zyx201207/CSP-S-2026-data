#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],m,ans[10000000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}

	for(int h=1;h<=n;h++)
	{
		for(int i=h;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[j]==a[i])
				{
					for(int k=i;k<j;k++)
					{
						a[i]=0; 
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]==i)
			{
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}

