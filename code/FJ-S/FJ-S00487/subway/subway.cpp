#include <bits/stdc++.h>
using namespace std;
const int N = 505,M = 5e5 + 5;
const long long inf = (1LL << 62);

int c,n,m,d,q;
long long t[M];
int k[N];
vector<int> station[N],a[N];

vector<pair<int,long long> > to[M];
void addedge(int u,int v,long long w)
{
	to[u].push_back({v,w});
	return;
}

long long w[N][N],dis[N][N];
void merge()
{
	for(int i = 1; i <= n; i++)
		for(int stNum = 0; stNum < k[i]; stNum++)
			addedge(station[i][stNum],i,a[i][stNum]);
	memset(w,0x3f,sizeof w);
	for(int i = 1; i <= n; i++)
		w[i][i] = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int stNum = 0; stNum < k[i]; stNum++)
		{
			for(auto& e : to[station[i][stNum]])
			{
				int j = e.first; long long cost = e.second;
				w[i][j] = min(w[i][j],a[i][stNum] + cost);
			}
		}	
	}
	return;
}
void floyd()
{
	memcpy(dis,w,sizeof w);
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	return;
}

long long query(int x,int y)
{
	long long ans = inf;
	for(auto& e1 : to[x])
		for(auto& e2 : to[y])
			ans = min(ans,t[x] + t[y] + e1.second + e2.second + dis[e1.first][e2.first]);
	return ans;
}

ifstream fin("subway.in",ios_base::in);
ofstream fout("subway.out",ios_base::out);

int main()
{
	ios::sync_with_stdio(0); fin.tie(0); fout.tie(0);
	fin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		fin >> t[i];
	for(int i = 1; i <= n; i++)
	{
		fin >> k[i];
		for(int j = 1; j <= k[i]; j++)
		{
			int to,dist; fin >> to >> dist;
			station[i].push_back(to);
			a[i].push_back(dist);
		}
	}
	merge();
	floyd();
	for(int i = 1; i <= q; i++)
	{
		int x,y; fin >> x >> y;
		fout << query(x,y) << '\n';
	}
	return 0;
}
/*
in1:
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
out1:
32
17

in2:
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
out2:
35
16
*/
