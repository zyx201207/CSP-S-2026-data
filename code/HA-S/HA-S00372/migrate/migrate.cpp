#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
using namespace std;
const int N=5050,INF=0x3f3f3f3f3f3f3f3f;
int op,T,n,d,dis[N],vis[N],pos[N],a[N];
vector<pr>g[N];
void dij(int st)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(pos,0,sizeof(pos));
	priority_queue<pr,vector<pr>,greater<pr>>q;
	q.push({0,st});
	dis[st]=0;
	pos[st]=1;
	while(q.size())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto i:g[x])
		{
			int y=i.first,v=i.second;
			if(vis[y]) continue;
			if(dis[x]+v<dis[y])
			{
				dis[y]=dis[x]+v;
				pos[y]=pos[x];
				q.push({dis[y],y});
			}
			else if(dis[x]+v==dis[y])
			{
				pos[y]=min(3ll,pos[y]+pos[x]);
			}
		}
	}
}
void solve_min()
{
	cin>>T;
	while(T--)
	{
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			g[i].clear();
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[j]-a[i]<=d)
				{
					g[i].push_back({j,1});
//					cout<<"build: "<<i<<' '<<j<<'\n';
				}
		for(int i=1;i<=n;i++)
		{
			dij(i);
			for(int j=i+1;j<=n;j++)
				if(pos[j]==2)
				{
					ans++;
//					cout<<i<<' '<<j<<' '<<dis[j]<<'\n';
				}
		}
		cout<<ans<<'\n';
	}
}
void solve_spA()
{
	cin>>T;
	while(T--)
	{
		int ans=0;
		cin>>n>>d;
		cin>>a[1]>>a[2];
		for(int i=3;i<=n;i++)
		{
			int x;cin>>x;
		}
		int D=a[2]-a[1];
		int maxx=d/D;
		if(maxx>=2) cout<<max(0ll,n-(2*maxx-1))<<'\n';
		else cout<<0<<'\n';
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>op;
	if(op<=10)
		solve_min();
	else if(op>=11&&op<=12)
		solve_spA();
	return 0;
}


