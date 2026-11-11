#include<bits/stdc++.h>
#define N 1000010
using namespace std;
bool vis[N],qwq[N];
int c,_,n,k;
int dis[N];
queue<int>q;
vector<int>ve[N];
void checkdfs(int u)
{
	vis[u]=1;
	for(auto &v:ve[u])
	{
		if(vis[v])
			continue;
		if(!qwq[v])
			continue;
		checkdfs(v);
	}
}
bool check()
{
	int tot=0;
	for(int i=1;i<=n;i++)
		vis[i]=0;
	for(int i=1;i<=n;i++)
		if(qwq[i]&&!vis[i])
		{
			tot++;
			if(tot>=3)
				return 0;
			checkdfs(i);
		}
	return 1;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>_;
	while(_--)
	{
		int Ans=1e9;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			ve[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		for(int i=0;i<(1<<n);i++)
		{
			int cnt=0,ans=0;
			for(int j=1;j<=n;j++)
			{
				qwq[j]=i&(1<<j-1);
				cnt+=qwq[j];
			}
			if(cnt!=k)
				continue;
			if(!check())
				continue;
			while(q.size())
				q.pop();
			for(int j=1;j<=n;j++)
			{
				if(qwq[j])
				{
					q.push(j);
					dis[j]=0;
				}
				else
					dis[j]=2*n;
			}
			while(q.size())
			{
				int u=q.front();
				q.pop();
				for(auto &v:ve[u])
					if(dis[v]>dis[u]+1)
					{
						q.push(v);
						dis[v]=dis[u]+1;
						ans=max(ans,dis[v]);
					}
			}
			Ans=min(Ans,ans);
		}
		cout<<Ans<<'\n';
	}
	return 0;
}
