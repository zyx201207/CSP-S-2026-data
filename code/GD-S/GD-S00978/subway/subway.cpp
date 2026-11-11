#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;

const int N = 2e5+6;
int c , n , m , d , q ,mk;
int dis[505][505];
vector<pair<int, int>>e[N];
priority_queue<pii,vector<pii>,greater<pii>>pq;
void dij(int s)
{
	for(int i=1;i<=505+mk;i++)
		dis[s][i] = (1ll<<59);
	dis[s][s]=0;
	pq.push({0,s});
	while(!pq.empty())
	{
		int u=pq.top().second,w=pq.top().first;
		pq.pop();
		if(dis[s][u]!=w)continue ;
		for(auto t:e[u])
		{
			int v=t.first,ww=t.second;
			if(dis[s][v] > dis[s][u]+ww)
			{
				dis[s][v]=dis[s][u]+ww;
				pq.push({dis[s][v],v});
			}
		}
	}
}
int w[N] , k[N];
int a[501][501],t[501][501];
void bbb(int u,int v,int w)
{
	e[u].push_back({v,w});
	e[v].push_back({u,w});
}
void solve()
{
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
		cin >> w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			if(j>=2)
			bbb(a[i][j],a[i][j-1],0);
			bbb(n+i,a[i][j],t[i][j]);
		}
	}
	for(int i=1;i<=n+n;i++)
		dij(i);
	for(int i=1,x,y;i<=q;i++)
	{
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x+n][y+n]<<'\n';
	}
	return ;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 13 16 19
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
10 285714285714285708
-1000000000000000000 -714285714285714292 -428571428571428584 -238095238095238112 -142857142857142876 -47619047619047640 142857142857142832 428571428571428540 714285714285714248 999999999999999956
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962

*/
