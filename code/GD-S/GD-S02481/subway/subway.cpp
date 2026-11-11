#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,M=5e5+5;
typedef long long ll;
typedef pair<ll,ll> PII;
ll c,n,m,d,q,w[M],dis[M],vis[M],a[N][20],t[N][20];
vector<PII> v[M];
void dij(ll start)
{
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<PII,vector<PII>,greater<PII> > q;
	dis[start]=0;
	q.push({dis[start],start});
	while(!q.empty())
	{
		PII p=q.top();
		ll px=p.second;
		q.pop();
		if(vis[px])
		{
			continue;
		}
		vis[px]=1;
		for(int i=0;i<v[px].size();i++)
		{
			ll tx=v[px][i].second,d=v[px][i].first;
			if(dis[tx]>dis[px]+d)
			{
				dis[tx]=dis[px]+d;
				q.push({dis[tx],tx});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			scanf("%lld%lld",&a[i][j],&t[i][j]);
		}
		for(int j=1;j<=k;j++)
		{
			for(int l=j;l<=k;l++)
			{
				ll sumt=t[i][j]+t[i][l];
				v[a[i][j]].push_back({sumt,a[i][l]});
				v[a[i][l]].push_back({sumt,a[i][j]});
			}
		}
		
	}
	while(q--)
	{
		ll x,y,ans;
		scanf("%lld%lld",&x,&y);
		dij(x);
		ans=w[x]+w[y]+dis[y];
		printf("%lld\n",ans);
	}
	return 0;
}
