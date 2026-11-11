#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
vector<int> g[maxn];
bool x[maxn],t[maxn],vis[maxn];
int n,k,dep[maxn][maxn],fa[maxn];
queue<int> q;
long long ans;
int find(int x)
{
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}
void bfs(int st)
{
	for(int i=1;i<=n;i++)vis[i]=0;
	q.push(st);
	dep[st][st]=0;
	vis[st]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto v:g[u])
		{
			if(vis[v])continue;
			dep[st][v]=dep[st][u]+1;
			vis[v]=1;
			q.push(v);
		}
	}
}
void co(int j,int k1)
{
	if(j>n+1||k1>k)return;
	if(k1==k)
	{
		if(j>n+1)return;
		if(j<n+1);
		else
		{
			for(int i=1;i<=n;i++)fa[i]=i,t[i]=0;
			for(int u=1;u<=n;u++)
			{
				for(auto v:g[u])
				{
					if(x[v]&&x[u])fa[find(u)]=find(v);
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(x[i]==0)continue;
				t[fa[i]]=1;
			}
			int s=0;
			for(int i=1;i<=n;i++)s+=t[i];
			if(s<=2)
			{
				long long maxx=0;
				for(int i=1;i<=n;i++)
				{
					if(x[i])continue;
					long long minn=INT_MAX;
					for(int j=1;j<=n;j++)
					{
						if(!x[j])continue;
						minn=min(minn,(long long)dep[i][j]);
					}
					maxx=max(maxx,minn);
				}
				ans=min(maxx,ans);
			}
			return;
		}
		
	}
	x[j]=1;
	co(j+1,k1+1);
	x[j]=0;
	co(j+1,k1);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		ans=INT_MAX;
		cin>>n>>k;
		int u,v;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++)bfs(i);
		co(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}

