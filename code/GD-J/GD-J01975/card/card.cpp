#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m,a[N];
int sum[M];
int b[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for (int i=1;i<=n;i++)
	{
		if (b[i]!=0)
		{
			for (int j=1;j<=n;j++)
			{
				if (b[j]!=0 && b[i]!=0)
				{
					if (i==j)
					{
						continue;
					}
					if (b[i]==b[j])
					{
						for (int k=1;k<j;k++)
						{
							b[i]=0;
						}
					}
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (b[i]==1 && sum[1]!=1)
		{
			sum[1]=1; 
		}
		if (b[i]==2 && sum[2]!=1)
		{
			sum[2]=1; 
		}
	}
	for (int i=2;i<=n;i++)
	{
		if (a[i]!=0)
		{
			for (int j=2;j<=n;j++)
			{
				if (a[j]!=0 && a[i]!=0)
				{
					if (i==j)
					{
						continue;
					}
					if (a[i]==a[j])
					{
						for (int k=2;k<j;k++)
						{
							a[i]=0;
						}
					}
				}
			}
		}
	}
	for (int i=2;i<=n;i++)
	{
		if (a[i]==1 && sum[1]!=2)
		{
			sum[1]=2;
		}
		if (a[i]==2 && sum[2]!=2)
		{
			sum[2]=2; 
		}
	}
	cout<<sum[1]<<" "<<sum[2];
	return 0;
}
