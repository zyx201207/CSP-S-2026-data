#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int>e[N];
bool flg[N];
int dis[N],f[N];
void init(int u,int fa,int k)
{
	f[u]=dis[u]=0;
	for(int v:e[u])
		if(v!=fa&&(!flg[u]||!flg[v]))init(v,u,k),dis[u]=max(dis[u],dis[v]+1),f[u]+=f[v];
	if(dis[u]>=k)f[u]++;
}
int solve(int u,int fa,int k)
{
	f[u]=dis[u]=0;
	int fir=0,mx=0,cnt=0;
	for(int v:e[u])
	{
		if(flg[u]&&flg[v])continue;
		f[u]+=f[v],cnt++;
		if(dis[v]>dis[fir])mx=dis[fir]+1,fir=v;
		else mx=max(mx,dis[v]+1);
	}
	dis[u]=dis[fir]+1;
	if(dis[u]>=k)f[u]++;
	int res=f[u];
/*	cout<<u<<' '<<f[u]<<'\n';
	for(int i=1;i<=5;i++)cout<<dis[i]<<' ';
	cout<<'\n';
	for(int i=1;i<=5;i++)cout<<f[i]<<' ';
	cout<<'\n';*/
	for(int v:e[u])
	{
		if(v==fa||flg[u]&&flg[v])continue;
		int t1=dis[u],t2=f[u];
		if(dis[u]>k)f[u]--;
		if(v==fir)dis[u]=mx;
		if(cnt==1)dis[u]=0;
		f[u]-=f[v];
		if(dis[u]>=k)f[u]++;
		res=min(res,solve(v,u,k));
		dis[u]=t1,f[u]=t2;
	}
	return res;
}
int check(int n,int k)
{
	init(1,0,k);
//	cout<<f[1]<<' ';
	int res=solve(1,0,k);
//	cout<<res<<'\n';
	for(int u=1;u<=n;u++)
	{
		for(int v:e[u])
		{
			int t1=u,t2=v;
			if(t1<t2)
			{
				flg[t1]=flg[t2]=true;
				init(t1,t2,k),init(t2,t1,k);
				int x=solve(t1,t2,k),y=solve(t2,t1,k);
//				cout<<u<<' '<<v<<' '<<x<<' '<<y<<'\n';
				res=min(res,x+y);
				flg[t1]=flg[t2]=false;
			}
		}
	}
	return res;
}
void work()
{
	int n,k;cin>>n>>k;
	for(int i=1,u,v;i<n;i++)cin>>u>>v,e[u].emplace_back(v),e[v].emplace_back(u);
//	cout<<check(n,1)<<'\n';
	int l=-1,r=n+1;
	for(;l+1<r;)
	{
		int mid=(l+r)>>1;
		if(check(n,mid)<=k)r=mid;
		else l=mid;
	}
	cout<<r<<'\n';
	for(int i=1;i<=n;i++)e[i].clear();
}
signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int _;cin>>_>>_;
//	_=1;
	for(;_;_--)work();
	return 0;
}