#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector <int> e[N];
int col[N];
int d[N];
int cnt;
int n,k;
void dfs(int u,int fa)
{
	if(fa&&col[u]!=col[fa]&&col[fa]==2) cnt++;
	for(auto v:e[u])
	{
		if(v==fa) continue;
		dfs(v,u);
	}
}
void dfs2(int u,int fa)
{
	for(auto v:e[u])
	{
		if(v==fa) continue;
		d[v]=d[u]+1;
		dfs2(v,u);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T,Ts;
	cin>>T>>Ts;
	while(Ts--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			e[i].clear();
			col[i]=0;
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int ans=n-1;
		for(int s=1;s<=(1<<n)-1;s++)
		{
			if(__builtin_popcount(s)>=k) continue;
			for(int i=1;i<=n;i++)
			{
				if(s&(1<<i-1)) col[i]=1;
				else col[i]=2;
			}
			cnt=0;
			dfs(1,0);
			if(cnt>2) continue;
			int cur=0;
			for(int i=1;i<=n;i++)
			{
				if(s&(1<<i-1)) continue;
				d[i]=0;
				dfs2(i,0);
				int ddis=n;
				for(int j=1;j<=n;j++)
				{
					if(s&(1<<j-1)) ddis=min(ddis,d[j]);
				}
				cur=max(cur,ddis);
			}
			ans=min(ans,cur);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
