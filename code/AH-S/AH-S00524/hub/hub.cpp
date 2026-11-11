#include<bits/stdc++.h>
using namespace std;
int dis[110][110],nm[110];
bool vis[110];
int u[110],v[110],ans,ans2;
//vector<int> o[110];
int n,k;
void dfs(int dep)
{
	if(dep==0)
	{
		ans2=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				dis[i][j]=dis[j][i]=1e9;
		}
		for(int i=1;i<=n-1;i++)
		{
			dis[u[i]][v[i]]=dis[v[i]][u[i]]=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
				//cout<<" "<<i<<" ";
				//for(auto j:o[i])
				{
				//	dis[i][j]=dis[j][i]=0;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int l=1;l<=n;l++)
				{
					dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
				}
			}
		}
			for(int i=1;i<=n;i++)
			{
				if(vis[i]) continue;
				int ans3=1e9;
				for(int j=1;j<=k;j++)
				{
					//cout<<i<<" "<<nm[j]<<" "<<dis[i][nm[j]]<<endl;
					if(dis[i][nm[j]]!=1e9) ans3=min(ans3,dis[i][nm[j]]);
				}
				ans2=max(ans2,ans3);
			}			
		ans=min(ans,ans2);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			nm[dep]=i;
			vis[i]=true;
			dfs(dep-1);
			vis[i]=false;
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			cin>>u[i]>>v[i];
		//	mp[u[i]][v[i]]=mp[v[i]][u[i]]=1;
		//	o[u[i]].push_back(v[i]);
		//	o[v[i]].push_back(u[i]);
		}
		ans=1e9;
		dfs(k);
		cout<<ans<<endl;
	}
	return 0;
}
