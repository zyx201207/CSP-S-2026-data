#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[100005],c[100005],sum[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int nu=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int ju=1;ju<=n;ju++)
	{
		for(int i=ju;i<=n;i++)
		{
			c[nu]=a[i];
			for(int z=1;z<i;z++)
			{
				if(c[z]==c[i])
				{
					for(int k=z;k<i;k++)
					{
						c[k]=0;
					}
				}
			}
			nu++;
		}
		nu=1;
		for(int w=1;w<=n;w++)
		{
			if(c[w]!=0)
			{
				sum[c[w]]++;
			}
		}
		for(int jj=1;jj<=n;jj++)
		{
			c[jj]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(sum[i]!=0)
			cout<<sum[i]<<' ';
	}
	return 0;
}
