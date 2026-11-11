#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505;
const int MAXM = 2e4+5;

struct for_G
{
	int line;
	int first;
	int second;
};

int n,m,d,q;
int w[MAXM];
int a[MAXN][MAXM];
int t[MAXN][MAXM];
int k[MAXN];

vector<for_G>G[MAXN][MAXM]; 
vector<pair<int,int>>line[MAXM];

struct for_dij
{
	int id;
	int dis;
	int line;
	bool const operator > (const for_dij a) const
	{
		return dis < a.dis;
	}
};

int Dijstra(int st,int st_line,int ed)
{
	int dis[MAXN][MAXM];
	memset(dis,0x3f,sizeof(dis));
	dis[st_line][st] = 0;
	priority_queue<for_dij,vector<for_dij>,greater<for_dij>> pq;
	pq.push({st,dis[st_line][st],st_line});
	while(!pq.empty())
	{
		int u = pq.top().id;
		int l = pq.top().line;
		pq.pop();
		for(for_G v : G[l][u])
		{
			if(dis[v.line][v.first] > dis[l][u] + v.second)
			{
				dis[v.line][v.first] = dis[l][u] + v.second;
				pq.push({v.first,dis[v.line][v.first],v.line});
			}
		}
	}
	int ret = 0x3f3f3f3f;
	for(pair<int,int>l : line[ed]) ret = min(ret,dis[l.first][ed]);
	return ret;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
			G[i][a[i][j]].push_back({i,a[i][j-1],0});
			G[i][a[i][j-1]].push_back({i,a[i][j],0});
			line[a[i][j]].push_back({i,j});
		}
	}
	
	for(int k = 1;k <= n;k++)
	{
		for(int i = 1;;i++)
		{
			if(a[k][i] == 0) break;
			for(pair<int,int> l : line[a[k][i]])
			{
				if(l.first == k) continue;
				G[l.first][a[k][i]].push_back({k,a[k][a[k][i]],t[k][i] + t[l.first][l.second]});
				G[k][a[k][i]].push_back({l.first,a[l.first][a[k][i]],t[k][i] + t[l.first][l.second]});
			}
		}
	}
	
	for(int r = 1;r <= q;r++)
	{
		int x,y;
		cin >> x >> y;
		int ret = 0x3f3f3f3f;
		for(pair<int,int>l : line[x]) ret = min(ret,Dijstra(x,l.first,y));
		cout << ret <<'\n';
	}
	return 0;
}

