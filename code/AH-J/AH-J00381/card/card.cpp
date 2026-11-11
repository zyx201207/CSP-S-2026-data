#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],b[500010];
int ans[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int t=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=t;j++)b[j]=0;
		t=0;
		for(int j=i;j<=n;j++)
		{
			b[++t]=a[j];
			for(int k=1;k<t;k++)
			{
				if(b[k]==a[j])
				{
					for(int l=k;l<t;l++)b[l]=0;
					b[k]=a[j],t=k;
				}
			}
		}
		for(int j=1;j<=t;j++)
		ans[b[j]]++;
	}
	for(int i=1;i<=m;i++)
	printf("%d ",ans[i]);
	return 0;
}
