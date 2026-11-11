#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],d[500005],le,ans[300005],b[500005];
bool f;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<a[i-1]) f=1;
//		c[i]=b[a[i]];
//		b[a[i]]=i;
	}
	if(!f)
	{
		for(int i=2;i<n+2;i++)
		{
			if(a[i]!=a[i-1]) printf("%d ",i-1);
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i-1])
		{
			for(int j=1;j<=le;j++) ans[d[j]]++;
			continue;
		}
		le=0;
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=le;k++)
			{
				if(d[k]==a[j])
				{
					le=k-1;
				}
			}
			d[++le]=a[j];
		}
		for(int j=1;j<=le;j++) ans[d[j]]++;
	}
	for(int j=1;j<=m;j++) printf("%d ",ans[j]);
	return 0;
}
