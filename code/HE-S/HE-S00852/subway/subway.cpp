#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int> 
#define mk make_pair
using namespace std;
const int N=(int)(2e6)+6;
const int inf=(int)(1e18);
int c,n,m,d,T,tot,dis[N];
bool vis[N];
vector <int> e[N],val[N];//建图
priority_queue<PII,vector<PII>,greater<PII> > q;
void dij(int s)
{
	for (int i=1;i<=tot;i++) 
	{
		dis[i]=inf;
		vis[i]=0;
	}
	dis[s]=0;
	q.push(mk(0,s));
	while (q.size())
	{
		int u=q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u]=1;
//		cout << u << " ";
		for (int i=0;i<(int)e[u].size();i++)
		{
			int v=e[u][i];
			int w=val[u][i];
			if (dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push(mk(dis[v],v));
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> T;
	for (int i=1,w;i<=m;i++)
	{
		cin >> w;
		e[i].push_back(i+m);
		e[i+m].push_back(i);
		val[i].push_back(w);
		val[i+m].push_back(w);
//		cout << i << " " << i+m << " " << w << "\n";
	}
	tot=2*m;
	for (int i=1,k;i<=n;i++)
	{
		cin >> k;
		int p=tot;
		for (int j=1,x,t;j<=k;j++)
		{
			cin >> x >> t;
			tot++;
			e[x+m].push_back(tot);
			e[tot].push_back(x+m);
			val[x+m].push_back(t);
			val[tot].push_back(t);
//			cout << x << " " << tot << " " << t << "\n";
			if (p==tot-1) continue;
			e[tot-1].push_back(tot);
			e[tot].push_back(tot-1);
			val[tot].push_back(0);
			val[tot-1].push_back(0);
//			cout << tot-1 << " " << tot << "\n";
		}
	}
	while (T--)
	{
		int x,y;
		cin >> x >> y;
		dij(x);
//		for (int i=1;i<=tot;i++)
//		{
//			cout << dis[i] << " ";
//		}
		cout << dis[y] << "\n";
	}
}
/*
貌似是最短路，考虑如何建模，建点建边 
首先是地铁口，1~m,地铁站，m+1~2*m
1对应m+1
复杂度O((2*m+sum(k))*(log(2*m+sum(k)))*q) 32pts 



0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
