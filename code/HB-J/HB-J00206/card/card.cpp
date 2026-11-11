#include<bits/stdc++.h>
using namespace std;
int n,m,s[500010],a[300010],c[300010];
int main()
{
	memset(c,0,sizeof c);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	for(int i=0;i<n;i++)
	{
		memset(a,0,sizeof a);
		int b=0;
		for(int j=i;j<n;j++,b++)
		{
			a[b]=s[j];
			for(int k=0;k<b;k++)
			{
				if(a[k]==a[b])
				{
					int h=k;
					while(a[++h]!=a[b])
					{
						a[h]=0;
					}
					b=k;
					break;
				}
			}
		}
		for(int j=0;j<b;j++)
		{
			c[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",c[i]);
	}
	return 0;
}
