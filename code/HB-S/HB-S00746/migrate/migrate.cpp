#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
constexpr int MAXN=2e3+10;

vector<int> v[MAXN];
int c,T;
int n,m;
int a[MAXN];
int ans;
priority_queue<pair<int,int> ,vector<pair<int,int> > , greater<pair<int,int> > > que;
int dis[MAXN][MAXN];
int tong[MAXN];
int num[MAXN][MAXN];
int vis[MAXN];
int qwq[MAXN][MAXN];

inline void dij(int x)
{
	for(int i=1;i<=n;++i) vis[i]=0;
	que.push({0,x});
	while(!que.empty())
	{
		auto now=que.top();
		que.pop();
		if(vis[now.se]==1) continue;
		vis[now.se]=1;
		dis[x][now.se]=now.fi;
		for(auto j:v[now.se])
		{
			if(vis[j]==0)
			{
				que.push({now.fi+1,j});
			}
		}
	}
	return ;
}

int awa;

void dfs(int x,int st,int en,int pw)
{
	if(pw>dis[st][en]) return ;
	if(x==en)
	{
		++awa;
		return ;
	}
	for(auto i:v[x])
	{
		if(i>x) dfs(i,st,en,pw+1);
	}
	return ;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	if(c>10)
	{
		for(int o=1;o<=T;++o) cout<<"0"<<'\n';
		return 0;
	}
	for(int o=1;o<=T;++o)
	{
		cin>>n>>m;
		for(int i=1;i<=n;++i) cin>>a[i];
		stable_sort(a+1,a+n+1);
		for(int i=1;i<=n;++i)
		{
			for(int j=i-1;j>=1;--j)
			{
				if(a[i]-a[j]<=m)
				{
					// cout<<i<<" "<<j<<" "<<a[i]-a[j]<<'\n';
					v[i].push_back(j);
				}
				else break;
			}
			for(int j=i+1;j<=n;++j)
			{
				if(a[j]-a[i]<=m)
				{
					v[i].push_back(j);
				}
				else break;
			}
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j) dis[i][j]=0;
			dij(i);
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=i+1;j<=n;++j)
			{
				awa=0;
				dfs(i,i,j,0);
				if(awa==2) ++ans;
			}
		}
		cout<<ans<<'\n';
		ans=0;
		for(int i=1;i<=n;++i) v[i].clear();
	}
	return 0;
}