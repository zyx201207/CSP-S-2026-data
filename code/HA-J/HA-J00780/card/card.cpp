#include <bits/stdc++.h>
using namespace std;
int a[200005],b[100005],n,m;
bool vis[500005];
int st[100005],p;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			b[a[j]]++;
			if(a[j]==a[j-1])b[a[j]]--;
		}
	/*for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof vis);
		for(int j=1;j<=n;j++)
		{
			if(vis[a[j]])
				while(p)
				{
					if(st[p]==a[j])
					{
						st[p]=0;
						break;
					}
					st[p]=0;
					p--;
				}
			st[++p]=a[j];
			vis[a[j]]=1;
		}
		while(p)
		{
			b[st[p]]++;
			st[p]=0;
			p--;
		}
	}*/
	for(int i=1;i<=m;i++)printf("%d ",b[i]);
	return 0;
}