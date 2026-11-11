#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int> 
#define mk make_pair
using namespace std;
const int N=1e6+5;
const int inf=1e18;
int c,T,n,k,dep[N],f[21][N],dis[N],ft[N];
vector <int> e[N],now;
map<PII,int> mp;
int find(int x){return ft[x]==x?x:ft[x]=find(ft[x]);}
void dfs(int u,int fa)
{
	f[0][u]=fa;
	for (int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		if (v==fa) continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
int lca(int x,int y)
{
	if (dep[x]>dep[y]) swap(x,y);
	int d=dep[y]-dep[x];
	for (int i=0;i<=20&&d;i++,d>>=1) 
		if (d&1)
			y=f[i][y];
	if (x==y) return x;
	for (int i=20;i>=0;i--)
	{
		if (f[i][x]!=f[i][y])
		{
			x=f[i][x];
			y=f[i][y];
		}
	}
	return f[x][0];
}
int calc(int x,int y)
{
	int LCA=lca(x,y);
	return dep[x]+dep[y]-2*dep[LCA];
}
void solve1()
{
	int ans=1e18;
	for (int i=0;i<(1ll<<n);i++)
	{
		int cnt=0;
		now.clear();
		for (int i=1;i<=n;i++)
		{
			ft[i]=i;
			dis[i]=inf;
		}
		for (int j=1;j<=n;j++)
		{
			if ((i>>(j-1))&1)
			{
				cnt++;
				now.push_back(j);
			}
		}
		if (cnt!=k) continue;
		int mx=0;
		for (int j=0;j<(int)now.size();j++)
		{
			for (int k=j+1;k<(int)now.size();k++)
			{
				int u=now[j];
				int v=now[k];
				if (mp.count(mk(u,v))||mp.count(mk(v,u)))
				{
					int fu=find(u);
					int fv=find(v);
					if (fu==fv) continue;
					ft[fu]=fv;
				}
			}
		}
		int tot=0;
		for (int j=0;j<now.size();j++)
		{
			if (ft[j]==j) tot++;
		}
		if (tot>2) continue;
		for (int j=1;j<=n;j++)
		{
			for (int k=0;k<now.size();k++)
			{
				dis[j]=min(dis[j],calc(now[k],j));
			}
			mx=max(mx,dis[j]);
		}
		ans=min(ans,mx);
	}
	cout << ans << "\n";
//	cout << "\n\n";
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> k;
		mp.clear();
		for (int i=1;i<=n;i++)
		{
			e[i].clear();
			ft[i]=i;
			dis[i]=inf;
		}
		for (int i=1,u,v;i<n;i++)
		{
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
			mp[mk(u,v)]=1;
		}
		dep[1]=1;
		dfs(1,0);
		for (int j=1;j<=20;j++)
		{
			for (int i=1;i<=n;i++)
			{
				f[j][i]=f[j-1][f[j-1][i]];
			}
		}
		if (n<=10) 
			solve1();
	}
}
/*
n<=10±¬ËÑ+ÅÐ¶Ï£¬15pts
 
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/ 
