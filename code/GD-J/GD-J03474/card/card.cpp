#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],c=1,d,e[300010];
int zs(int x)
{
	for (int i=1;i<=c;i++)
	{
		if (b[i]==x)
		{
			d=i;
			return 0;
		}
	}
	return 1;
}
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
		c=1;
		d=0;
		for (int j=i;j<=n;j++)
		{
			if (zs(a[j])==1)
			{
				b[c]=a[j];
				c++;
			}
			else
			{
				for (int x=d;x<=c;x++)
				{
					b[x]=0;
				}
				c=d;
			}
		}
		for (int j=1;j<=c;j++)
		{
			cout << b[j] << " ";
			e[b[j]]++;
		}
	}
	for (int i=1;i<=m;i++)
	{
		cout << e[i] << " ";
	}
	return 0;
} 
