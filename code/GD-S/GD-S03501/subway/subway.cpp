#include<bits/stdc++.h>
using namespace std;
struct ddb
{
	long long a,t;
} b[500005][22];
long long n,m,d,T,dis[505][505],a[550000],ans;
vector<ddb> v[505];
bool vis[505];
priority_queue<ddb> q;
bool operator<(const ddb &a,const ddb &b)
{
	return a.t>b.t;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>T;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		for(int j=1;j<=t;j++)
		{
			int ta,tb;
			cin>>ta>>tb;
			for(int k=1;k<=b[ta][0].a;k++)
			{
				v[b[ta][k].a].push_back({i,b[ta][k].t+tb});
				v[i].push_back({b[ta][k].a,b[ta][k].t+tb});
			}
			b[ta][++b[ta][0].a].a=i;
			b[ta][b[ta][0].a].t=tb;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=1e18;
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		q.push({i,0});
		dis[i][i]=0;
		while(!q.empty())
		{
			ddb ls=q.top();
			q.pop();
			if(vis[ls.a])
				continue;
			vis[ls.a]=true;
			for(int k=0;k<v[ls.a].size();k++)
			{
				ddb j=v[ls.a][k];
				if(dis[i][j.a]>dis[i][ls.a]+j.t)
				{
					dis[i][j.a]=dis[i][ls.a]+j.t;
					q.push({j.a,dis[i][j.a]});
				}
			}
		}
	}
	while(T--)
	{
		int st,en;
		cin>>st>>en;
		ans=1e18;
		for(int i=1;i<=b[st][0].a;i++)
			for(int j=1;j<=b[en][0].a;j++)
				ans=min(ans,dis[b[st][i].a][b[en][j].a]+b[st][i].t+b[en][j].t);
		cout<<ans+a[st]+a[en]<<'\n';
	}
	return 0;
}
