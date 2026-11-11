#include <bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[300001];
pair<int,bool>vis[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			if (vis[a[j]].second)
				for (int k=vis[a[j]].first;k<j;k++)
					vis[a[k]].second=false;
			vis[a[j]]={j,true};	
		}			
		for (int j=1;j<=m;j++)
		{
			if (vis[j].second)
				ans[j]++;
			vis[j]={0,false};
		}
	}
	for (int i=1;i<=m;i++)
		printf("%d ",ans[i]);
}
