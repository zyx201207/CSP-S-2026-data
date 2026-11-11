#include<bits/stdc++.h>
using namespace std;
int n,m,a[200020],sum[200020],vis[200020],mark[200020];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof vis);
		memset(mark,0,sizeof mark);
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]])
			{
				for(int k=vis[a[j]];k<j;k++) vis[a[k]]=0,mark[k]=1;
				vis[a[j]]=j;
			}
			else vis[a[j]]=j;
		}
		for(int j=i;j<=n;j++) sum[a[j]]+=(mark[j]==0);
	}
	for(int i=1;i<=m;i++) printf("%d ",sum[i]);
	return 0;
}
