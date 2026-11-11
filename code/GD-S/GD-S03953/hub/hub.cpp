#include<bits/stdc++.h>
using namespace std;
const int N=100;
int c,T,n,k;
bool in[N],vis[N];
vector<int> g[N];
void dfs(int u)
{
	vis[u]=1;
	for(int v:g[u])
		if(in[v]&&!vis[v])dfs(v);
}
int calc(int u,int fa)
{
	if(in[u])return 0;
	int res=n;
	for(int v:g[u])
	{
		if(v==fa)continue;
		res=min(res,calc(v,u)+1);
	}
	return res;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1; i<=n; i++)g[i].clear();
		for(int i=1,x,y; i<n; i++)
		{
			cin>>x>>y;
			g[x].emplace_back(y);
			g[y].emplace_back(x);
		}
		int ans=n;
		for(int i=1; i<(1<<n); i++)
		{
			int res=0,cnt=0;
			if(__builtin_popcount(i)!=k)continue;
			for(int j=1; j<=n; j++)in[j]=(i>>j-1)&1,vis[j]=0;
			for(int j=1; j<=n; j++)if(in[j]&&!vis[j])dfs(j),cnt++;
			if(cnt>2)continue;
			for(int j=1; j<=n; j++)res=max(res,calc(j,0));
			ans=min(ans,res);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
