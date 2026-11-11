#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5],c[m+1],b[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		c[i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			b[j]=a[j-i+1];
			for(int x=1;x<j;x++)
			{
				if (b[x]==b[j])
				{
					for(int y=x;y<j;y++)
					{
						b[y]=0;
					}
					b[x]=b[j];
					b[j]=0;
				}
			}
			for(int t=1;t<=n+1;t++)
			{
				c[b[t]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
}
