#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int a[N];
int mn[N],dist[N];
int vis[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		memset(mn,0,sizeof(mn));
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			cnt++;
			if(vis[a[j]]==0)
			{
				mn[cnt]=a[j];
				vis[a[j]]=cnt;
			}
			else
			{
				for(int k=vis[a[j]]+1;k<=cnt;k++)vis[mn[k]]=0;
				cnt=vis[j];
			}
		}
		for(int j=1;j<=m;j++)if(vis[j]!=0)dist[j]++;
	}
	for(int i=1;i<=m;i++)cout<<dist[i]<<' ';
	return 0;
}
