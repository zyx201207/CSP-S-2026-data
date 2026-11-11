#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define pii pair< int , pair<int,int> >
using namespace std;
const int N = 5e5 + 5,M = 505;
int c,n,m,D,p,tp[N]; 
vector< pair<int,int> > e[N];
int t[N][N],d[N][M];
void dij(int s,int x)
{
	priority_queue< pii, vector<pii> , greater<pii> > q;
	q.push({0, {s,x} });
	d[s][s] = 0;
	while (!q.empty())
	{
		int dis = q.top().first,u = q.top().second.first,x = q.top().second.second;
		q.pop();
		if (d[s][u] > dis)
			continue;
		for (int i = 0;i < e[u].size();i++)
		{
			int v = e[u][i].first,xv = e[u][i].second,w;
			if (xv != x)
				w = t[u][xv] + t[u][x];
			if (dis + w > d[s][v])
			{
				d[s][v] = dis + w;
				q.push({dis + w, {v,xv} });
			}
		}
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> m >> n >> D >> p;
	for (int i = 1;i <= n;i++)
		cin >> tp[i];
	for (int i = 1;i <= m;i++)
	{
		int k,s,oth;
		cin >> k >> s >> oth;
		t[s][i] = oth;
		for (int j = 2;j <= k;j++)
		{
			int x,y;
			cin >> x >> y;
			e[x].push_back({s,i});
			e[s].push_back({x,i});
			t[x][i] = y;
			s = x;
		}
	}
	memset(d,0x3f,sizeof(d));
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (t[i][j])
				dij(i,j);
	while (p --)
	{
		int x,y;
		cin >> x >> y;
		cout << d[x][y] + tp[x] + tp[y] << '\n';
	}
	return 0;
}
