#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001];
int b[1001][1001],ls=0,c[1001]={0},k,num[1001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int q=1;q<=n;q++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int y=1;y<=m;y++)
			{
				b[j][y]=0;
			}
		}
		for(int i=q;i<=n;i++)
		{
			for(int y=1;y<=m;y++)
			{
				c[y]=0;
			}
			for(int j=1;j<=i;j++)
			{
				b[i][j]=a[q];
				k=b[i][j];
				if(c[k]==1)
				{	
					for(int t=1;t<=i;t++)
					{
						if(b[i][t]==b[i][j])
						{
							ls=t;
							break;
							}
						}
					for(int p=ls+1;p<=n;p++)
					{
						b[i][p]=0;
					}
				}
				else
				{
					c[k]=1;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(b[n][i]==q)
			{
				num[q]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<num[i]<<" ";
	}
	return 0;
}
