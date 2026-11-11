#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<tuple>
#include<list>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define fi first
#define se second
#define eb emplace_back
const int maxn=1e6+5;
const int inf=1e7+5;
int c,t,n,k,mid,ret;
bool vis[maxn];
pll f[maxn][3];
int g[maxn],z[maxn];
vector<int> e[maxn];
void dfs1(int x,int fa)
{
	g[x]=0,z[x]=inf;
	for(int i:e[x])
	{
		if(i==fa) continue;
		dfs1(i,x);
		g[x]=max(g[x],g[i]+1);
		z[x]=min(z[x],z[i]+1);
	}
	if(z[x]+g[x]<=mid) g[x]=-1;
	if(g[x]==mid||(x==1&&g[x]>=0))
	{
		ret++;
		vis[x]=1;
		z[x]=0;
		g[x]=-1;
	}
}
void dfs2(int x,int fa)
{
	if(vis[x])
	{
		f[x][0]={inf,inf};
		f[x][1]={0,0};
		f[x][2]={inf,inf};
	}
	else
	{
		f[x][0]={0,0};
		f[x][1]={inf,inf};
		f[x][2]={inf,inf};
	}
	for(int i:e[x])
	{
		if(i==fa) continue;
		dfs2(i,x);
		pll sd[3];
		sd[0]={f[x][0].fi+f[i][0].fi,f[x][0].se+f[i][0].se};
		sd[1]=min(make_pair(f[x][0].fi+f[i][1].fi,f[x][0].se+f[i][1].se+1),make_pair(f[x][1].fi+f[i][0].fi,f[x][1].se+f[i][0].se));
		sd[1]=min(sd[1],{f[x][1].fi+f[i][1].fi+f[i][1].se+f[x][1].se,0});
		sd[2]=min(make_pair(f[x][0].fi+f[i][2].fi,f[x][0].se+f[i][2].se+1),{f[x][2].fi+f[i][0].fi,f[x][2].se+f[i][0].se});
		sd[2]=min(sd[2],{f[x][1].fi+f[i][1].fi,min(f[x][1].se,f[i][1].se+1)});
		for(int j=0;j<3;j++) f[x][j]=sd[j];
	}
}
bool check()
{
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		z[i]=g[i]=0;
		for(int j=0;j<=2;j++) f[i][j]={};
	}
	ret=0;
	dfs1(1,0);
	dfs2(1,0);
	if(ret+min(f[1][1],f[1][2]).fi<=k) return true;
	return false;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int l,r;
			cin>>l>>r;
			e[l].eb(r);
			e[r].eb(l);
		}
		int l=0,r=n,ans=0;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check())
			{
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) e[i].clear();
	}
	return 0;
}
