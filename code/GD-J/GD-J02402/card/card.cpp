#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],sum[300010],a1[500010],x;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.ans","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		x=0;
		sum[a[i]]++;
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]==a[j-1])
			{
				sum[a[j]]--;
				a[j]=-1;
				a1[x]=j;
				x++;
			}
			else
				sum[a[j]]++;
		}
		for(int z=0;z<x;z++)
			a[a1[z]]=a[a1[z]-1];
	}
	for(int i=1;i<=m;i++)
		printf("%d ",sum[i]);
	return 0;
}
