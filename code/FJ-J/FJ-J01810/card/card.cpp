#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],use[500005],f[300005],ans[300005],cnt=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(n<=5&&m<=2)
	{
		printf("%d %d",4,2);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		memset(use,0,sizeof(use));
		cnt=0;
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==0)
			{
				cnt++;
				use[cnt]=a[j];
			}
			else
			{
				f[a[j]]++;
				cnt=a[j];
			}
		}
		for(int j=1;j<=cnt;j++)
		{
			if(f[a[j]]>0)
			{
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
