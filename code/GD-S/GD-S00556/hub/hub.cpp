#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
int C,T,n,k,ans;
vector<int> e[N];
bool vis[11],hub[11]; 
void dfs(int u)
{
	vis[u]=1;
	for(auto v:e[u])
	{
		if(vis[v]||!hub[v]) continue;
		dfs(v);
	}
}
int findhub(int u)
{
	vis[u]=1;
	if(hub[u]) return 0;
	int res=0x3f3f3f3f;
	for(auto v:e[u])
	{
		if(vis[v]) continue;
		res=min(res,findhub(v)+1);
	}
	return res;
}
void solve_Sub1()
{
	for(int i=1;i<=n;i++) e[i].clear();
	ans=0x3f3f3f3f;
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v),e[v].push_back(u);
	}
	for(int mask=0;mask<(1<<n);mask++)
	{
		memset(hub,0,sizeof(hub));
		int count=0;
		for(int i=0;i<n;i++) if((mask>>i)&1) count++,hub[i+1]=1;
		if(count!=k) continue;
		count=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&hub[i])
			{
				dfs(i);
				count++;
			}
		}
		if(count>2) continue;
		count=0;
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));	
			count=max(count,findhub(i)); 
		}
		ans=min(ans,count);
	}
	cout<<ans<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	if(C<=3)
	{
		while(T--) solve_Sub1();
	}
	return 0;
} 
