#include <bits/stdc++.h>
using namespace std;
long long n,m,a[600000],tong[600000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for (int i=1;i<=n;i++)
	{
		int l=i,zhi=1,zhuo[600000]={};
		while (l<=n)
		{
			for (int k=1;k<=zhi;k++)
			{
				if (zhuo[k]==a[l])
				{
					for (int t=k;t<=zhi;t++)
					{
						zhuo[t]=0;
					}
					zhi=zhi-(zhi-k);
				}
				break;
			}
			zhuo[zhi]=a[l];
			zhi++;
			l++;
		}
		for (int k=1;k<zhi;k++)
		{
			tong[zhuo[k]]++;
		}
	}
	for (int i=1;i<=m;i++)
	{
		if (i==m)
		{
			cout << tong[i] ;
		}
		else 
		{
			cout << tong [i] << " ";
		}
	}
	return 0;
}
