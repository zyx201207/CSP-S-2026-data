#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1000000000000000000ll;
int c,n,m,d,q;
ll w[500050];
struct nd
{
	int v;
	ll d;
};
vector<nd> e[500050];
ll dis[550][550];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a;
			ll t;
			cin>>a>>t;
			e[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) dis[i][j]=inf;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<e[i].size();j++)
		{
			int u=e[i][j].v;
			ll t1=e[i][j].d;
			for(int k=0;k<e[i].size();k++)
			{
				if(j==k) continue;
				int v=e[i][k].v;
				ll t2=e[i][k].d;
				ll nt=t1+t2;
				if(nt<dis[u][v]) dis[u][v]=dis[v][u]=nt;
				//cout<<u<<' '<<v<<endl;
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) 
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) cout<<dis[i][j]<<' ';
		cout<<endl;
	}*/
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(int j=0;j<e[x].size();j++)
		{
			int u=e[x][j].v;
			ll t1=e[x][j].d;
			for(int k=0;k<e[y].size();k++)
			{
				int v=e[y][k].v;
				ll t2=e[y][k].d;
				//cout<<u<<' '<<v<<' '<<t1<<' '<<t2<<endl;
				ll nt=t1+t2+dis[u][v];
				ans=min(ans,nt);
			}
		}
		ans=ans+w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}
