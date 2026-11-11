#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,D,Q,vis[501];
ll w[500001],f[501],ff[501][501];
vector<int>q[500001],p[501];
vector<ll>t[500001];
vector<pair<int,ll> >d[501];
struct aaa
{
	int x;
	ll w;
};
operator<(aaa x,aaa y)
{
	return x.w>y.w;
}
priority_queue<aaa>h;
ll dij(int u)
{
	for(int i=1;i<=n;i++) f[i]=1e18,vis[i]=0;
	f[u]=0;
	h.push(aaa{u,0});
	while(!h.empty())
	{
		int k=h.top().x;
		h.pop();
		if(vis[k]) continue;
		vis[k]=1;
		for(int i=0;i<d[k].size();i++)
		{
			int x=d[k][i].first;
			ll y=d[k][i].second;
			if(f[x]>f[k]+y)
			{
				f[x]=f[k]+y;
				h.push(aaa{x,f[x]});
			}
		}
	}
	for(int i=1;i<=n;i++) ff[u][i]=f[i];
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		dij(i);
	}
}
ll solve(int u,int v)
{
	if(u==v) return 0;
	ll ans=1e18,num=0;
	for(int i=0;i<q[u].size();i++)
	{
		for(int j=0;j<q[v].size();j++)
		{
			int x=q[u][i],y=q[v][j];
			num=ff[x][y]+w[u]+w[v]+t[u][i]+t[v][j];
			ans=min(ans,num);
		}
	}
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&D,&Q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	int a=0,o=0;
	ll b=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&o);
		for(int j=1;j<=o;j++)
		{
			scanf("%d%lld",&a,&b);
			p[i].push_back(a);
			t[a].push_back(b);
			q[a].push_back(i);
		}
	}
	int x=0,y=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<q[i].size();j++)
		{
			for(int k=j+1;k<q[i].size();k++)
			{
				x=q[i][j],y=q[i][k];
				d[x].push_back(make_pair(y,t[i][j]+t[i][k]));
				d[y].push_back(make_pair(x,t[i][j]+t[i][k]));
			}
		}
	}
	init();
	while(Q--)
	{
		scanf("%d%d",&x,&y);
		printf("%lld\n",solve(x,y));
	}
	return 0;
}
