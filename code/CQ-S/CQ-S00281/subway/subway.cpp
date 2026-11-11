#include<bits/stdc++.h>
#define ll long long
//#define int ll//#
#define db double
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const ll inf=1e18;
const db eps=1e-7;
const int mod=1e9+7;
int c,n,m,d,q,b[500005];
int k[500005];
vector<pii>l[500005];//可达line
vector<pii>s[500005];//可达station
ll e[505][505];
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(k==i)continue;
			for(int j=1;j<=n;j++)
			{
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
//		scanf("%d",&b[i]);
	}
	int u,v,w;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
//		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			cin>>u>>v;
//			scanf("%d%d",&u,&v);
			s[i].pb({u,v});
			l[u].pb({i,v});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)e[i][j]=inf;
	}
//	cerr<<"ok0\n";
	ll w0;
	for(int i=1;i<=n;i++)
	{
		e[i][i]=0;
		for(int j=1;j<=k[i];j++)
		{
			u=s[i][j-1].fi;
			w0=s[i][j-1].se;
			for(auto line:l[u])
			{
				if(line.fi==i)continue;
				v=line.fi,w=line.se;
				e[i][v]=min(e[i][v],w+w0);
				e[v][i]=min(e[v][i],w+w0);
			}
		}
	}
//	cerr<<"ok1\n";
	floyd();
//	cerr<<"ok2\n";
	ll ans,num;
	while(q--)
	{
		ans=inf;
		cin>>u>>v;
//		scanf("%d%d",&u,&v);
		for(auto l1:l[u])
		{
			for(auto l2:l[v])
			{
				num=e[l1.fi][l2.fi]+l1.se+l2.se;
				if(num<ans)ans=num;
			}
		}
//		printf("%lld\n",);
		cout<<ans+b[u]+b[v]<<"\n";
	}
	return 0;
}
