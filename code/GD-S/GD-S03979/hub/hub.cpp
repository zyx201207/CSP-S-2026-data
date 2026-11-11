#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100+5,inf=1e9;

int n,k,ans;

bool f[N];

int fa[N];
vector<int>tr[N];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void dfs(int u,int cnt)
{
	if(cnt>k)return ;
	if(cnt+n-u+1<k) return ;
	
	if(u>n)
	{
		for(int i=1;i<=n;i++)
		{
			if(!f[i])fa[i]=-1;
			else fa[i]=i;
		}
		for(int u=1;u<=n;u++)	
		{
			if(!f[u])continue;
			for(int v:tr[u])
			{
				if(!f[v])continue;		
				
				int x=find(u),y=find(v);
				if(x==y)continue;
				fa[x]=y;
			}
		}
		int cc=0;
		for(int i=1;i<=n;i++)
		{
			if(fa[i]==i)cc++;
			if(cc>2)return ;
		}
		int res=0;
		vector<bool>vis(n+1,0);
		queue<pair<int,int>>q;
		for(int i=1;i<=n;i++)
		{
			if(f[i])
				q.push({i,0});
		}
		while(!q.empty())
		{
			int u=q.front().first,dd=q.front().second;
			q.pop();
			if(vis[u]) continue;
			vis[u]=1;
			res=max(res,dd);
			
			for(int v:tr[u])
			{
				if(vis[v])continue;
				q.push({v,dd+1});
			}	
		} 
		ans=min(ans,res);
		return ;
	}
	
	
	f[u]=1;
	dfs(u+1,cnt+1);
	f[u]=0;
	
	dfs(u+1,cnt);
}
void solve()
{
	cin>>n>>k;
	ans=inf;
	for(int i=1;i<=n;i++)	
		tr[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;cin>>u>>v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	dfs(1,0);
	cout<<ans<<"\n";
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	
	int c,T;
	cin>>c>>T;
	while(T--)
		solve();
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5

*/
