#include<bits/stdc++.h>
using namespace std;
constexpr int N=110;
int c,T,n,m;
vector <int> g[N];
int siz[N][N][N];
void dfs(int k,int rt,int fa)
{
	siz[rt][k][0]=1;
	for(auto u:g[k])
	{
		if(u==fa) continue;
		dfs(u,rt,k);
		for(int i=1;i<=n;i++)
			siz[rt][k][i]+=siz[rt][u][i-1];
	}
	for(int i=n;i>=1;i--)
		siz[rt][k][i]+=siz[rt][k][i-1];
}
inline bool check(int mid)
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<=mid;j++)
		{
			int res=0;
			for(auto u:g[i])
				res+=max(siz[i][u][j],siz[i][u][mid-j]);
			if(res-(int)g[i].size()+1>=m) return 1;
		}
	return 0;
}
inline void init()
{
	for(int i=1;i<=n;i++)
		g[i].clear();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=0;k<n;k++)
				siz[i][j][k]=0;
}
inline void solve()
{
	cin>>n>>m;
	for(int i=1,x,y;i<n;i++)
	{
		cin>>x>>y;
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	for(int i=1;i<=n;i++)
		dfs(i,i,0);
	int l=0,r=n,ans=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d\n",ans);
	init();
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
		solve();
	return 0;
}
