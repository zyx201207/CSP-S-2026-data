#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
bool s[N],vis[N];
vector<int> g[N];
void dfs(int u)
{
	for(int v:g[u])
		if(s[v]&&!vis[v])
		{
			vis[v]=1;
			dfs(v);
		}
}
int dist(int st)
{
	memset(vis,0,sizeof(vis));
	queue<pair<int,int>> q;
	q.push({st,0});
	while(!q.empty())
	{
		int u=q.front().first,S=q.front().second;
		q.pop();
		vis[u]=1;
		if(s[u]) return S;
		for(int v:g[u])
			if(!vis[v])
				q.push({v,S+1});
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int c,t,n,k,i,u,v,mask,sz,cp,ans;
	cin>>c>>t;
	while(t--)
	{
		ans=INT_MAX;
		cin>>n>>k;
		for(i=1;i<=n;i++) g[i].clear();
		for(i=1;i<n;i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(mask=0;mask<=(1<<n);mask++)
		{
			memset(vis,0,sizeof(vis));
			sz=cp=0;
			for(i=0;i<n;i++)
				if((mask>>i)&1)
				{
					s[i+1]=1; 
					sz++;
				}
				else s[i+1]=0;
			if(sz!=k) continue;
			for(i=1;i<=n;i++)
				if(!vis[i]&&s[i])
				{
					dfs(i);
					cp++;
				}
			if(cp>2) continue;
			int sum=0;
			for(i=1;i<=n;i++) sum=max(sum,dist(i));
			ans=min(ans,sum);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
