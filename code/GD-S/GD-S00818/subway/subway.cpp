#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int read()
{
	int res = 0,f = 1;
	char ch = getchar();
	while (ch<'0'||ch>'9') f = (ch=='-'?-f:f),ch = getchar();
	while (ch>='0'&&ch<='9') res = (res<<3)+(res<<1)+(ch^48),ch = getchar();
	return res*f;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
void writech(int x,char ch){write(x),putchar(ch);}
const int N = 5e5+5,M = 505;
int C,n,m,d,Q;
int w[N];
vector<int> a[M],c[M];
vector<pii> e[N];
int dist[M][M];
bool vis[M];
void dij(int s)
{
	for (int i = 1; i <= n; i++) dist[s][i]=2e18,vis[i]=false;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({0,s});
	dist[s][s]=0;
	while (q.size())
	{
		int d = q.top().first;
		int x = q.top().second;
		q.pop();
		if (vis[x]) continue;
		vis[x]=true;
		for (int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i];
			if (dist[s][y]>d+c[x][i])
			{
				dist[s][y]=d+c[x][i];
				if (!vis[y]) q.push({dist[s][y],y});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read(),n=read(),m=read(),d=read(),Q=read();
	for (int i = 1; i <= m; i++) w[i]=read();
	for (int i = 1; i <= n; i++)
	{
		int len=read();
		for (int j = 1; j <= len; j++)
		{
			int x=read(),t=read();
			e[x].push_back({t,i});
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < e[i].size(); j++)
		{
			int x = e[i][j].second;
			for (int k = j+1; k < e[i].size(); k++)
			{
				int y = e[i][k].second;
				int z = e[i][j].first+e[i][k].first;
				a[x].push_back(y);
				c[x].push_back(z);
				a[y].push_back(x);
				c[y].push_back(z);
			}
		}
	}
	for (int i = 1; i <= n; i++) dij(i);
	while (Q--)
	{
		int x=read(),y=read();
		int ans = 2e18;
		for (int i = 0; i < e[x].size(); i++)
		{
			for (int j = 0; j < e[y].size(); j++)
			{
				int t = w[x]+w[y]+e[x][i].first+e[y][j].first+dist[e[x][i].second][e[y][j].second];
				ans=min(ans,t);
			}
		}
		writech(ans,'\n');
	}
	return 0;
}

