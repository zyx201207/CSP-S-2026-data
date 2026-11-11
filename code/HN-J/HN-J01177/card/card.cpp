#include<bits/stdc++.h>
using namespace std;
int a[1000];
int b[10000];
int c[1000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	int p=n;
	int o=0;
	for(int x=0;x<p;x++)
	{
		for(int i=o;i<n;i++)
		{
			b[i]=c[i];	
			for(int j=o;j<i;j++)
			{
				if(b[i]==b[j])
				{
					for(int y=j;y<i;y++)
					{
						b[y]=0;
					}
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=o;j<n;j++)
			{
				if(b[j]==i)
				{
					a[i]++;
				}
			}
		}
		o++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<a[i]<<' ';
	}
	return 0;	
} 
