#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],vis[300010],ans[500010],sum[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	int x=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ans[j]=0;
			vis[j]=0;
		}
		for(int j=i;j<n;j++)
		{
			ans[x]=a[j];
			if(vis[ans[x]])x++;
			else
			{
				vis[ans[x]]++;
				sum[a[j]]++;
				x++;		
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
	return 0;
}
