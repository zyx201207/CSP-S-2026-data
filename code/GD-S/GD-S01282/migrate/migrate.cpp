#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10,M=5e3+10,inf=1e9;
struct st
{
	ll v,w;
	bool operator < (const st &X) const
	{
		return w>X.w;
	}
};
ll n,d,ans,dis[N],a[N],cnt[N];
vector<st> g[N];
void dijkstra(ll s)
{
	priority_queue<st> q;
	dis[s]=0;
	cnt[s]=1;
	q.push({s,0});
	while(!q.empty())
	{
		ll u=q.top().v;
		q.pop();
		for(auto c:g[u])
		{
			ll v=c.v,w=c.w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				cnt[v]=cnt[u];
				q.push({v,dis[v]});
			}
			else if(dis[v]==dis[u]+w)
			{
				cnt[v]+=cnt[u];
//				q.push({v,dis[v]});
			}
		}
	}
}
void solve()
{
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
//		cnt[i]=0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[i]<=d)
			{
				g[i].push_back({j,1});
				g[j].push_back({i,1});
			}
		 } 
	}
	for(int i=1;i<=n;i++)
	{
		dijkstra(i);
		for(int j=1;j<=n;j++) 
		{
			dis[j]=inf;
			if(cnt[j]==2) ans++;
//			cout<<cnt[j]<<' ';
			cnt[j]=0;
		}
	}
//	cout<<endl;
	cout<<ans<<endl;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	ll c,t;
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

