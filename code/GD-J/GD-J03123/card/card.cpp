#include<bits/stdc++.h>
using namespace std;
int a[500005],jg[30005];
bool c[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int num=1;num<=n;num++)
	{
		for(int i=1;i<=m;i++)
		{
			c[i]=0;
		}
		for(int i=num;i<=n;i++)
		{
			if(c[a[i]]==1)
			{
				for(int j=1;j<=m;j++)
				{
					c[j]=0;
				}
			}
			c[a[i]]=1;
		}
		for(int i=1;i<=m;i++)
		{
			if(c[i])
			{
				jg[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",jg[i]); 
	}
	return 0;
}
