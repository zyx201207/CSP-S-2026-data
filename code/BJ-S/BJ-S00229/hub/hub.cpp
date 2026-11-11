#include<bits/stdc++.h>
using namespace std;
int chosed[105];
int n,k;
int vis[105];
int dis[105];
int f[105];
int ans=1e9;
vector<int>g[105];
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y)
{
	f[find(x)]=find(y);
}
void ranse(int x)
{
	// cout<<x<<endl;
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i];
		if(!chosed[y])continue;
		if(vis[y])continue;
		vis[y]=1;
		ranse(y);
	}
}
void solve()
{
	
	//首先检查是不是两个连通块
	memset(vis,0,sizeof(vis));
	int cnt=0;

	for(int i=1;i<=n;i++)
	{
		if(chosed[i]&&!vis[i])
		{
			cnt++;
			ranse(i);
		}
	}
	// cout<<"cntcheck "<<cnt<<endl;
	if(cnt!=2)
	{
		return;
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	cout<<chosed[i]<<" ";
	// }
	// cout<<endl;
	// cout<<233<<endl;
	// memset(vis,0,sizeof(vis));
	int ansrp=0;
	for(int i=1;i<=n;i++)
	{
		if(!chosed[i])//枚举每个选择之外的城市
		{
			int ansnow=1e9;
			queue<int>q;
			q.push(i);
			for(int j=1;j<=n;j++)
			{
				dis[j]=1e9;
				vis[j]=0;

			}
			dis[i]=0;
			while(!q.empty())
			{
				int f=q.front();
				q.pop();
				vis[f]=0;
				for(int j=0;j<g[f].size();j++)
				{
					int y=g[f][j];
					if(dis[y]>dis[f]+1)
					{
						dis[y]=dis[f]+1;
						if (!vis[y])
						{
							vis[y]=1;
							q.push(y);
						}
					}
				}
			}
			for(int j=1;j<=n;j++)
			{
				if(chosed[j])
				{
					// cout<<i<<" "<<dis[j]<<endl;
					ansnow=min(ansnow,dis[j]);
				}
			}
			ansrp=max(ansrp,ansnow);
			// cout<<"rp"<<" "<<ansrp<<endl;
		}
	}
	ans=min(ans,ansrp);
}
void dfs(int x,int k,int step)
{
	// cout<<x<<" "<<k<<" "<<step<<endl;
	
	if(x==n+1&&step==k)
	{
		solve();
		return;
	}
	if(x>n)return;
	
	// cout<<x<<" "<<k<<" "<<step<<endl;
	// cout<<x<<" "<
	chosed[x]=0;
	dfs(x+1,k,step);
	chosed[x]=1;
	if(step+1<=k)dfs(x+1,k,step+1);
	chosed[x]=0;

}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{	
		ans=1e9;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			// tong[u][v]=tong[v][u]=1;
		}
		dfs(1,k,0);
		cout<<ans<<endl;
	}
	return 0;
}