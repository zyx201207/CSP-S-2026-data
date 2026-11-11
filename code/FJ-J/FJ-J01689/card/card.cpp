#include<bits/stdc++.h>
using namespace std;
int n,m,a[511111],b[311111],c[311111],d[311111],e[511111],bb[311111];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			e[j]=a[j];
		}
		for(int j=i;j<=n;j++)
		{
			b[e[j]]++;
			if(b[e[j]]==1)
			{
				d[e[j]]=i;
			}
			if(b[e[j]]>1)
			{
				for(int k=d[e[j]];k<j;k++)
				{
					b[e[k]]--;
				}
			}
			for(int k=i;k<=n;k++)
			{
				if(b[e[k]]>0)
				bb[e[k]]++;
				if(bb[e[k]]==1)
				{
					d[e[j]]=i;
				}
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(b[e[j]]>0)
			{
				c[e[j]]++;
				b[e[j]]=0;
				bb[e[j]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
} 
