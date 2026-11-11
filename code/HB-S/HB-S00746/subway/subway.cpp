#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
constexpr int MAXN=2e4+10;
constexpr int MAXQ=1e5+10;

vector<pair<int,int> > Q[MAXN];
int c,n,m,d,q;
vector<pair<int,int> > v[MAXN*20];
int a[MAXN];
int k,xx1,xx2,yy2;
int dis[MAXN];
int vis[MAXN*20];
int cnt;
int st,en;
priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > que;
int ans[MAXQ];

inline void dij(int x)
{
	que.push({0,x});
	for(int i=1;i<=cnt;++i) vis[i]=0;
	while(!que.empty())
	{
		auto now=que.top();
		que.pop();
		// cout<<now.se<<endl;
		if(vis[now.se]==1) continue;
		vis[now.se]=1;
		if(now.se<=n) dis[now.se]=dis[now.se]=now.fi;
		for(auto i:v[now.se])
		{
			if(vis[i.first]==0)
			{
				que.push({now.fi+i.se,i.fi});
			}
		}
	}
	return ;
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;++i) cin>>a[i];
	cnt=n;
	for(int i=1;i<=m;++i)
	{
		cin>>k;
		xx1=0;
		++cnt;
		for(int j=1;j<=k;++j)
		{
			cin>>xx2>>yy2;
			v[cnt].push_back({xx2,yy2});
			v[xx2].push_back({cnt,yy2});
		}
	}
	// for(int i=1;i<=cnt;++i)
	// {
	// 	cout<<i<<'\n';
	// 	for(auto j:v[i]) cout<<j.fi<<" "<<j.se<<'\n';
	// 	cout<<'\n';
	// }
	for(int i=1;i<=q;++i)
	{
		cin>>st>>en;
		if(st>en) swap(st,en);
		Q[st].push_back({en,i});
	}
	for(int i=1;i<=n;++i)
	{
		if(Q[i].size()>0) dij(i);
		for(auto j:Q[i])
		{
			ans[j.se]=dis[j.fi]+a[i]+a[j.fi];
		}
	}
	for(int i=1;i<=q;++i) cout<<ans[i]<<'\n';
	return 0;
}