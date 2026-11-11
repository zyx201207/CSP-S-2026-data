#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[300000+10];
int a[500000+10],b[500000+10];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int h=1;h<=m;h++)
		{
			b[h]=a[h];
			a[h]=0;
			for(int j=1;j<=m;j++)
			{
				if(a[j]==b[h])
				{
					for(int w=h;w<=j;w++)
					{
						a[h]=b[w];
						b[w]=0;
					}
					b[h]=a[j];
				}
			}
		}
		for(int e=1;e<=n;e++)
		{
			if(b[e]==i)
			{
				ans[e]++;
			}
		}
	}
	cout<<ans[1];
	for(int i=2;i<=m;i++)
	{
		cout<<" "<<ans[i];
	}
	return 0;
} 
