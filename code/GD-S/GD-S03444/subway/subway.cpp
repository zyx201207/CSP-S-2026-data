#include <bits/stdc++.h>
#define int long long
using namespace std;
int m;
struct lx
{
	int ai,ti;
}sz[500005];
struct lx2
{
	int e,w;
}temp;
int w[500005];
int dis[500005];
bool vis[500005];
vector <lx2> v[500005];
bool operator< (lx2 a,lx2 b)
{
	return a.w > b.w;
}
priority_queue<lx2,vector<lx2>,less<lx2> >q;
void dij(int a)
{
	for (int i = 1;i <= m;i++)
		dis[i] = 0x7fffffff,vis[i] = 0;
	dis[a] = 0;
	q.push({a,0});
	while (!q.empty())
	{
		temp = q.top();
		q.pop();
		if (vis[temp.e])
			continue;
		vis[temp.e] = 1;
		for (lx2 i:v[temp.e])
		{
			if (dis[i.e] > dis[temp.e]+i.w)
			{
				dis[i.e] = dis[temp.e]+i.w;
				q.push({i.e,dis[i.e]});
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,d,q,ki,ai,ti,s,t;
	cin >> c >>n >> m >>d >> q;
	for (int i = 1;i <= m;i++)
		cin >> w[i];
	for (int i = 1;i <= n;i++)
	{
		cin >> ki;
		for (int j = 1;j <= ki;j++)
		{
			cin >> sz[j].ai >> sz[j].ti;
//			if (j != 1)
//				v[sz[j].ai].push_back({sz[j-1].ai,sz[j].ti+sz[j-1].ti}),v[sz[j-1].ai].push_back({sz[j].ai,sz[j].ti+sz[j-1].ti});
		} 
		for (int j = 1;j <= ki;j++)
		{
			for (int k = j+1;k <= ki;k++)
			{
				v[sz[j].ai].push_back({sz[k].ai,sz[j].ti+sz[k].ti}),v[sz[k].ai].push_back({sz[j].ai,sz[j].ti+sz[k].ti});
			} 
		}
	}
	for (int i = 1;i <= q;i++)
	{
		cin >> s >> t;
		dij(s);
		cout << dis[t]+w[s]+w[t] << '\n';
	}
	return 0;
} 
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
