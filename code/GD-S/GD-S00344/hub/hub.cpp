#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
long long c,t,n,k,ans;
vector <long long> edge[110];
bool vis[110],vi[110];
inline long long check()
{
	for(long long i=1;i<=n;i++) vi[i]=0;
	long long sum=0,ret=0;
	for(long long i=1;i<=n;i++)
	{
		if((!vis[i])||vi[i]) continue;
		sum++;
		if(sum>2) return inf;
		queue <long long> q;
		q.push(i);
		vi[i]=1;
		while(!q.empty())
		{
			long long now=q.front();q.pop();
			for(long long to:edge[now])
			{
				if(vis[to]&&(!vi[to]))
				{
					vi[to]=1;
					q.push(to);
				}
			}
		}
	}
	for(long long i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		queue <long long> q,len;
		q.push(i),len.push(0);
		bool flag=0;
		while(!q.empty())
		{
			long long Q=q.front(),L=len.front();
			q.pop(),len.pop();
			for(long long to:edge[Q])
			{
				if(vis[to])
				{
					ret=max(ret,L+1);
					flag=1;
					break;
				}
				q.push(to),len.push(L+1);
			}
			if(flag) break;
		}
	}
	return ret;
}
void dfs(long long num,long long k)
{
	if(k==0)
	{
		ans=min(ans,check());
		return;
	}
	for(int i=num;i<=n-k+1;i++)
	{
		vis[i]=1;
		dfs(i+1,k-1);
		vis[i]=0;
	}
	return;
}
inline void solve()
{
	ans=inf;
	cin>>n>>k;
	for(int i=1;i<=n;i++) edge[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		edge[u].emplace_back(v);
		edge[v].emplace_back(u);
	}
	dfs(1,k);
	cout<<ans<<'\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--) solve();
}
