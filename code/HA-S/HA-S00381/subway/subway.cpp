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
const int N=2e5+505;
const int mod=1e9+7;
const int inf=1e18;
vector<vector<pair<int,int>>> g,e;
vector<int> w;
int qwe,n,m,d,Q;
vector<vector<int>> q,dis;
inline void dij(int s)
{
	vector<int> r(m+n+1,0);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> di;
	di.push({0,s});
	dis[s][s]=0;
	while(!di.empty())
	{
		int dd=di.top().fi,u=di.top().se;
		di.pop();
		if(r[u]) continue;
		r[u]=1;
		for(auto y:g[u])
		{
			int ddd=y.se,id=y.fi;
			if(dis[s][id]>dis[s][u]+ddd)
			{
				dis[s][id]=dis[s][u]+ddd;
				di.push({dis[s][id],id});
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef dui
	freopen(".out","r",stdin);
	freopen(".out","w",stdout);
#endif
#ifndef che
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
#ifdef CCF
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
#endif
	cin>>qwe>>n>>m>>d>>Q;
	w.resize(m+1);
	dis.resize(m+n+1,vector<int>(m+n+1,inf));
	e.resize(n+1);
	for(int i=1;i<=m;i++) cin>>w[i];
	g.resize(m+n+1);
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int l=1;l<=k;l++)
		{
			int a,t;
			cin>>a>>t;
			g[a].push_back({i+m,t});
			g[i+m].push_back({a,t});
		}
	}
	vector<int> is(m+1,0);
	while(Q--)
	{
		int l,r;
		cin>>l>>r;
		if(l>r) swap(l,r);
		if(!is[l])
		{
			dij(l);
			is[l]=1;
		}
		cout<<w[l]+dis[l][r]+w[r]<<"\n";
	}
	return 0;
}
//cout<<fixed<<setprecision(10);
//printf("%,3f,);
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
