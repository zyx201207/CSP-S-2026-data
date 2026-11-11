#include<bits/stdc++.h>
using namespace std;
int n=0,m=0;
int a[500010]={0};
int b[500010]={0};
int ans[500010]={0};
bool vis[500010]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];b[i]=a[i];
	}
	for(int u=1;u<=n;u++)
	{
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)a[i]=b[i];
		for(int i=u;i<=n;i++)
		{
			if(vis[a[i]])
			{
				for(int j=i-1;a[j]!=a[i];j--)
				{
					vis[a[j]]=0;a[j]=0;
				}
				a[i]=0;
			}
			vis[a[i]]=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(vis[i])ans[i]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	
	return 0;
}
//48
