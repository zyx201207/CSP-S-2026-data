#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10,M = 510;
vector<pair<int,ll> > e[N];
vector<pair<int,ll> > a[M];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
ll c,n,m,d,Q,w[N];
ll A[M][M],dis[M][M];
int pd[N];
ll read();
void write(ll x);
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read(),n = read(),m = read(),d = read(),Q = read();
	for(int i=1;i<=m;i++) w[i] = read();
	memset(A,0x3f,sizeof(A));
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		ll k = read();
		for(int j=1;j<=k;j++)
		{
			int x = read();
			int len = e[x].size();
			ll t = read();
			e[x].push_back(make_pair(i,t));
			for(ll p = 0;p<len;p++)
			{
				int v = e[x][p].first;
				ll T = e[x][p].second;
				if(t + T < A[i][v]) A[i][v] = A[v][i] = t + T;
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(A[i][j] != 0x3f3f3f3f3f3f3f3f)
			{
				a[i].push_back(make_pair(j,A[i][j]));
				a[j].push_back(make_pair(i,A[j][i]));
			}
	for(int i=1;i<=n;i++)
	{
		memset(pd,0,sizeof(pd));
		q.push(make_pair(0,i));
		while(!q.empty())
		{
			while(!q.empty() and pd[q.top().second]) q.pop();
			if(q.empty()) break;
			ll T = q.top().first;
			int x = q.top().second;
			q.pop(); pd[x] = 1;
			dis[i][x] = T;
			int len = a[x].size();
			for(int j=0;j<len;j++)
			{
				int v = a[x][j].first;
				ll W = a[x][j].second;
				if(pd[v] or W == 0x3f3f3f3f3f3f3f3f) continue;
				if(T + W < dis[i][v])
				{
					dis[i][v] = T + W;
					q.push(make_pair(dis[i][v],v));
				}
			}
		}
	}
	while(Q--)
	{
		ll x = read(),y = read();
		ll ans = 0x3f3f3f3f3f3f3f3f;
		int lenx = e[x].size(),leny = e[y].size();
		for(int i=0;i<lenx;i++)
			for(int j=0;j<leny;j++)
				ans = min(ans,w[x] + w[y] + e[x][i].second + e[y][j].second + dis[e[x][i].first][e[y][j].first]);
		write(ans);
		puts("");
	}
	return 0;
}

ll read()
{
	ll s = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s*f;
}

void write(ll x)
{
	if(x < 0) putchar('-'),x = -x;
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
