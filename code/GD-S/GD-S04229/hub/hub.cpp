#include<bits/stdc++.h>
using namespace std;

const int N=310;
int n,k;
vector<int> g[N];

int dep[N],up[N][10];
void lca_dfs(int cur,int pre)
{
	up[cur][0]=pre;
	for(int nxt:g[cur])
		if(nxt!=pre)
			lca_dfs(nxt,cur);
}
void lca_init()
{
	for(int k=1;k<=9;k++)
		for(int u=1;u<=n;u++)
			up[u][k]=up[up[u][k-1]][k-1];
}
int lca(int u,int v)
{
	if(dep[u]<dep[v])
		swap(u,v);
	int d=dep[u]-dep[v];
	for(int k=9;k>=0;k--)
		if(d&(1<<k)) u=up[u][k];
	if(u==v) return u;
	for(int k=9;k>=0;k--)
		if(up[u][k]!=up[v][k])
			u=up[u][k],v=up[v][k];
	return up[u][0];
}

bool c[N];

bool chklt(int u)
{
	for(int v:g[u])
		if(c[v])
			return false;
	return true;
}

int ans;

void dfs(int u,int cnt)
{
	if(u>n)
	{
		int mx=0;
		for(int u=1;u<=n;u++)
			if(!c[u])
			{
				int res=1e5;
				for(int v=1;v<=n;v++)
					if(c[v])
						res=min(res,dep[u]+dep[v]-2*dep[lca(u,v)]); 
				mx=max(mx,res);
			}
		ans=min(ans,mx);
		return;
	}
	if(cnt>2) return;
	c[u]=true;
	dfs(u+1,cnt+chklt(u));
	c[u]=false;
	dfs(u+1,cnt);
}

void clear()
{
	ans=1e5;
}

void solve()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int u,v; cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	lca_dfs(1,0);
	lca_init();
	dfs(1,0);
	cout<<ans<<'\n';
}


int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T; cin>>c>>T;
	while(T--) solve();
	return 0;
}

