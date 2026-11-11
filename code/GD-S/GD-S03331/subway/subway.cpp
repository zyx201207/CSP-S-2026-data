#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,Q,u,v,w[500005],k[505],sum,dis[500005],vis[500005];
map<int,int>a[505],t[505];
vector<int>q[500005];
queue<int>p;
void spfa(int x)
{
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	while(!p.empty())
	{
		p.pop();
	}
	vis[x]=1;
	p.push(x);
	dis[x]=0;
	while(p.size())
	{
		x=p.front();
		p.pop();
		vis[x]=0;
		for(auto i:q[x])
		{
			int z;
			for(int j=1;j<=k[i];j++)
			{
				if(a[i][j]==x)
				{
					z=j;
				}
			}
			for(int j=1;j<=k[i];j++)
			{
				if(a[i][j]!=x)
				{
					if(dis[a[i][j]]>dis[x]+t[i][j])
					{
						dis[a[i][j]]=dis[x]+t[i][j]+t[i][z];
						if(!vis[a[i][j]])
						{
							vis[a[i][j]]=0;
							p.push(a[i][j]);
						}
					}
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			q[a[i][j]].push_back(i);
		}
	}
	while(Q--)
	{
		cin>>u>>v;
		sum=w[u]+w[v];
		spfa(u);
		cout<<sum+dis[v]<<'\n';
	}
	return 0;
}
