#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,T;
int n,k;
vector<int> G[N];
int ans;
bool bl[N];
int fa[N];
int getfa(int u){return ((u==fa[u])?u:getfa(fa[u]));}
int dis[N];
void Dfs(int u,int fa)
{
	if(bl[u])dis[u]=0;
	else dis[u]=N;
	for(int v:G[u])
	{
		if(v==fa)continue;
		Dfs(v,u);
		dis[u]=min(dis[u],dis[v]+1);
	}
}
void dfs(int u)
{
	if(u==n+1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(bl[i])cnt++;
		if(cnt!=k)return ;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=n;i++)
		{
			if(bl[i])
			{
				for(int v:G[i])
					if(bl[v])fa[getfa(i)]=getfa(v);
			}
		}
		vector<int> vc;
		for(int i=1;i<=n;i++)
			if(bl[i])vc.push_back(getfa(i));
		sort(vc.begin(),vc.end());
		vc.erase(unique(vc.begin(),vc.end()),vc.end());
		if(vc.size()>2)return ;
		int ANS=0;
		for(int i=1;i<=n;i++)
		{
			Dfs(i,0);
			ANS=max(ANS,dis[i]);
		}
		ans=min(ans,ANS);
		return ;
	}
	bl[u]=0;
	dfs(u+1);
	bl[u]=1;
	dfs(u+1);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		for(int i=1;i<=n;i++)G[i].clear();
		ans=N;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1);
		cout<<ans<<'\n';
	}
	
	return 0;
}
