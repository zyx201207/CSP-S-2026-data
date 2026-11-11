#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,jian=0;
	cin>>n>>m;
	int a[n+10],b[n+10],biao[m+10],zong[m+1];
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int j=1;j<=n;j++)
	{
		memset(biao,0,sizeof(biao));
		memset(zong,0,sizeof(zong));
		for(int i=1;i<=n;i++)
		{
			if(biao[a[i]]==0)
			{
				biao[a[i]]=i;
			}
			else
			{
				for(int k=biao[a[i]];k<=n;k++)
				{
					b[k]=b[k+biao[a[i]]];
				}
				
			}
		}
		
		for(int i=1;i<=m;i++)
		{
			zong[b[i]]++;
		}
		for(int i=1;i<=n;i++)
		{
			a[i]=a[i+1];
			b[i]=a[i];
		}
	}
	
	for(int i=1;i<=m;i++)
	{		
		cout<<zong[i]<<' ';
	}
	return 0;
} 
