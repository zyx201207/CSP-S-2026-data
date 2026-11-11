#include<bits/stdc++.h>
using namespace std;
int n,m;
int card[500010];
int a[500010];	
int turn[500010];
bool vis[300010];
int ans[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>card[i];
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=1;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		memset(turn,0,sizeof(turn));
		for(int j=i;j<=n;j++)
		{
			if(!vis[card[j]])
			{
				vis[card[j]]=1;	 
				a[cnt]=card[j];	
				turn[a[cnt]]=cnt;
				cnt++;
			}
			else
			{
				cnt=turn[card[j]];
				int start=turn[card[j]];	
				for(int t=start;t<=j;t++)
				{
					vis[a[t]]=0;
					turn[a[t]]=0;
					a[t]=0;
				}
				a[cnt]=card[j];
				vis[card[j]]=1;
				turn[a[cnt]]=cnt;
				cnt++;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(vis[j]==1) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
