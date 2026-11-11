#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300010],a[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		
		int cnt[300010]={0};
		for(int j=i;j<=n;j++)
		{
			cnt[a[j]]++;
			if(cnt[a[j]]>1)
			{
				for(int k=j-1;a[k]!=a[j];k--)cnt[a[k]]=0;
				cnt[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(cnt[j]>0)
			{
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
