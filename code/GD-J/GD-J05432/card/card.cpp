#include <bits/stdc++.h>
using namespace std;

int n,m,a[500005],b[300005];

int mo(int x,int c[500005])
{
	for(int i=1;i<=500005;i++)
	{
		if(c[i]==x) return i;
	}
	return -1;
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int c[500005],t=1;
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++)
		{
			if(mo(j,c)==-1) 
			{
				c[t]=j;
				t++;
				continue;
			}
			else
			{
				for(int o=mo(j,c);o<=t;o++)
				{
					c[o]=0;
				}
				c[mo(j,c)]=j;
				t=mo(j,c)+1;
			}
		}
		for(int j=1;j<t;j++)
		{
			b[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
	return 0;
}
