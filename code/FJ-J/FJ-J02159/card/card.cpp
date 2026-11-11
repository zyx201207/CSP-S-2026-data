#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[500010]={0},b[500010]={0},c[300010]={0},d[300010]={0};
int main()
{
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int x=1;
	for(int i=1;i<=n;i++)
	{
		if(d[i]==0)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i]==a[j]&&d[j]==0)
				{
				    d[j]=x;
				}
			}
			x++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			b[j]=d[j];
			if(b[i]==b[j]&&i!=j)
			{
				for(int k=j;k<i;k++)
				{
					b[k]=0;
				}
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(b[j]>0)
			{
				c[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
}
