#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e6+9;
const int Y=6e3+9;
const ll INF=4e18;
struct E
{
	int v;
	ll w;
};
struct Q
{
	int u;
	ll w;
	bool operator < (const Q& a) const
	{
		return w>a.w;
	}
};
priority_queue<Q> q;
vector<E> e[MAXN];
int n,m;
ll a[MAXN];
ll dis[Y][Y];
int cnt[Y][Y];
void dij(int s)
{
	bool ft[Y];
	for(int i=1;i<=n;i++)
	{
		dis[s][i]=INF;
		ft[i]=0;
		cnt[s][i]=1;
	}
	dis[s][s]=0;
	q.push({s,0});
	while(!q.empty())
	{
		int u=q.top().u;
		q.pop();
		if(ft[u]) continue;
		ft[u]=1;
		for(auto qwq:e[u])
		{
			int v=qwq.v;
			ll w=qwq.w;
			if(w>m) continue;
			if(dis[s][v]==dis[s][u]+w) cnt[s][v]+=cnt[s][u];
			if(dis[s][v]>dis[s][u]+w)
			{
				dis[s][v]=dis[s][u]+w;
				q.push({v,dis[s][v]});
				cnt[s][v]=cnt[s][u];
			}
		}
	}
}
void special()
{
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ll u=a[2]-a[1];
	if(u<=m && m<3*u)
	{
		cout<<n-3<<"\n";
	}
	else
	{
		cout<<0<<"\n";
	}
}
void solve()
{
	cin>>n>>m;
	if(n<=3)
	{
		cout<<0<<"\n";
		return ;
	}
	if(n>5000)
	{
		special();
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			e[i].push_back({j,abs(a[i]-a[j])});
		}
	}
	for(int i=1;i<=n-3;i++)
	{
		dij(i);
	}
	int ans=0;
	for(int i=1;i<=n-3;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dis[i][j]<=m &&cnt[i][j]==2 && j-i+1>=4)
			{
				ans++;
			}
			
		}
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)
	{
		e[i].clear();
	}
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    
    int c,T;
    cin>>c>>T;
    while(T--)
    {
    	solve();
	}
    
    return 0;
}
