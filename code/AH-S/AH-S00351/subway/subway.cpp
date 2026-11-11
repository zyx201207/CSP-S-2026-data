#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N=5e5+5,M=505;
struct lin
{
	int id,tim;
};
int i,j,c,n,m,d,q,w[N],k[N],g[M][M],u,v,s,t,kka,kkb;
vector<lin>a[N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)g[i][j]=1e14;
	}
	for(i=1;i<=n;i++)g[i][i]=0;
	for(i=1;i<=n;i++)
	{
		cin>>k[i];
		for(j=1;j<=k[i];j++)
		{
			cin>>u>>v;
			for(kka=0;kka<(int)a[u].size();kka++)g[a[u][kka].id][i]=g[i][a[u][kka].id]=a[u][kka].tim+v;//在本站换乘的线路之间的边权
			a[u].push_back({i,v});//将线路加入点中
		}
	}
	for(kka=1;kka<=n;kka++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)g[i][j]=min(g[i][j],g[i][kka]+g[kka][j]);
		}
	}//求线路的floyd
	while(q--)
	{
		int ans=1e15;
		cin>>s>>t;
		for(i=0;i<(int)a[s].size();i++)//枚举线路
		{
			for(j=0;j<(int)a[t].size();j++)
			{
				ans=min(ans,g[a[s][i].id][a[t][j].id]+a[s][i].tim+a[t][j].tim);//求最短路
			}
		}
		cout<<ans+w[s]+w[t]<<endl;
	}
}
