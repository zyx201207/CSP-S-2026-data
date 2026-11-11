#include<bits/stdc++.h>//172.16.12.5
using namespace std;

#ifdef LOCAL
#define debug(x) cerr<<#x<<" = "<<(x)<<'\n';
#else
#define debug(x)
#endif
#define ll long long
#define vct vector
#define pb push_back
#define PII pair<int,int>
#define int long long

#ifdef LOCAL
bool ____ST;
#endif
int c,n,m,d,q,w[500010],dis[505][505];
vct<PII>vec[500010];
#ifdef LOCAL
bool ____ED;
#endif

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef LOCAL
	cerr<<double(&____ED-&____ST)/(1024*1024)<<"Mib\n";
	double ____st=clock();
#endif
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			for(auto p:vec[a])
			{
				dis[p.first][i]=dis[i][p.first]=min(dis[i][p.first],t+p.second);
			}
			vec[a].pb({i,t});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				dis[j][k]=min(dis[j][i]+dis[i][k],dis[j][k]);
			}
		}
	}
	while(q--)
	{
		int x,y,minn=0x3f3f3f3f3f3f3f3f;
		cin>>x>>y;
		for(auto p1:vec[x])
		{
			for(auto p2:vec[y])
			{
				minn=min(minn,dis[p1.first][p2.first]+p1.second+p2.second);
			}
		}
		cout<<minn+w[x]+w[y]<<'\n';
	}
#ifdef LOCAL
	double ____ed=clock();
	cerr<<'\n'<<(____ed-____st)/CLOCKS_PER_SEC*1000<<"ms\n";
#endif
	return 0;
}
