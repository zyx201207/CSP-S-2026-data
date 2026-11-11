#include<bits/stdc++.h>

//#define int long long

using namespace std;

const int N=105,inf=1e9;

int c,T=1,n,k,ans;

int mp[N][N],dis[N];

bool vis[N],is[N];

vector<int> e[N];

int check()
{
	int cnt=k,res=-1;
	for(int i=1;i<=n;i++)
	{
		if(is[i]==0) continue;
		for(int j=i+1;j<=n;j++)
		{
			if(is[j]==0) continue;
			if(mp[i][j]) cnt--;
		}
	}
	if(cnt>2) return inf;
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(is[i])
		{
			dis[i]=0;
			vis[i]=1;
			q.push(i);
		}
		else dis[i]=inf,vis[i]=0;
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto v:e[u])
		{
			if(vis[v]) continue;
			vis[v]=1;
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}
	for(int i=1;i<=n;i++)
	{
		res=max(res,dis[i]);
	}
	return res;
}

void dfs(int t,int s)
{
	if(t==n+1)
	{
		if(s==k) ans=min(ans,check());
		return;
	}
	dfs(t+1,s);
	is[t]=1;
	dfs(t+1,s+1);
	is[t]=0;
	return;
}

void solve()
{
	cin>>n>>k;
	for(int u,v,i=1;i<n;i++)
	{
		cin>>u>>v;
		mp[u][v]=mp[v][u]=1;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	ans=inf;
	dfs(1,0);
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)
	{
		e[i].clear();
		for(int j=1;j<=n;j++) mp[i][j]=0;
	}
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}

