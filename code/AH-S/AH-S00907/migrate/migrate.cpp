#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[50001],vis[1001],dis[1001];
void dfs(int pos,int step)
{
	if(step<dis[pos])
	{
		dis[pos]=step;
		vis[pos]=1;
	}
	else if(step==dis[pos])
	{
		vis[pos]++;
	}
	for(int i=pos+1;x[i]-x[pos]<=d&&i<=n;i++) dfs(i,step+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		int sum=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<n;i++)
		{
			memset(vis,0,sizeof(vis));
			memset(dis,127,sizeof(dis));
			dfs(i,0);
			for(int j=i+1;j<=n;j++)
			{
				if(vis[j]==2) sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
