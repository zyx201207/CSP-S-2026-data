#include<bits/stdc++.h>
using namespace std;
int a[500001],b[500001],c[300001],flag[500001],m,n;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)c[j]=0;
		for(int j=i;j<=n;j++)
		{
			if(c[a[j]])for(int k=c[a[j]];k<j;k++)b[k]=0;
			b[j]=a[j],c[a[j]]=j;
		}
		for(int j=i;j<=n;j++)if(b[j])flag[b[j]]++,b[j]=0;
	}
	for(int i=1;i<=m;i++)printf("%d ",flag[i]);
	return 0;
}
