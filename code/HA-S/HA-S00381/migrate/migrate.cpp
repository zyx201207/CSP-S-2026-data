#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define fi first
#define se second
#define be begin()
#define en end()
#define CCF
#define che
#define dui
using namespace std;
const int N=2e6+5;
const int mod=1e9+7;
const int inf=1e18;
int n,d;
int ci[N];
ull a[N];
vector<int> g[N];
inline void dij(int s)
{
	vector<int> r(n+1,0),dis(n+1,inf);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> di;
	di.push({0,s});
	dis[s]=0;
	ci[s]=1;
	while(!di.empty())
	{
		int u=di.top().se;
		di.pop();
		if(r[u]) continue;
		r[u]=1;
		for(auto y:g[u])
		{
			if(y==u) continue;
			if(dis[y]>dis[u]+1)
			{
				dis[y]=dis[u]+1;
				ci[y]=1;
				di.push({dis[y],y});
			}
			else if(dis[y]==dis[u]+1) ci[y]+=ci[u];
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef che
	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
#endif
#ifdef CCF
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
#endif
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		if(n<4)
		{
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++) 
		{
			g[i].clear();
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int l=1+i;l<=n;l++)
			{
				if(abs(a[l]-a[i]>d)) break;
				g[i].push_back(l);
				g[l].push_back(i);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int l=1;l<=n;l++) ci[l]=0;
			dij(i);
			for(int l=1;l<=n;l++) if(ci[l]==2) ans++;
		}
		cout<<ans/2<<"\n";
	}
	return 0;
}
/*
0 1
5 3
-3 0 2 3 4
*/
