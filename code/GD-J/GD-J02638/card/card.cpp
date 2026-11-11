#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int b[10000];
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	long long n=0,m=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=i;j<=n;k++)
			{
				if(a[k]==a[j])
				{
					for(int o=j;o<=k;o++)
					{
						a[o]=0;
					}
				}
			}
		}
		for(int ii=1;ii<=m;ii++)
		{
			for(int jj=1;jj<=n;jj++)
			{
				if(a[jj]==ii)
				{
					b[ii]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << b[i];
	}
}
