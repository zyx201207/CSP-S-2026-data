#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const long long N = 1e6+5;//?
vector<pair<long long,long long> >g[N];
long long dis[N],w[N],k[N],vis[N],spfa[1005][1005];

struct AAA{
	long long now,v;
	bool operator <(const AAA& others)const
	{
		return v > others.v;
	}
};

long long djsk(long long s,long long to)
{
	priority_queue<AAA>q;
	q.push({s,0});
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	dis[s] = 0;
	while(!q.empty())
	{
		auto tp = q.top();
		q.pop();
		long long now = tp.now;
		if(vis[now])continue;
		vis[now] = 1;
		//cout << now << endl;
		for(auto i : g[now])
		{
			if(dis[now] + i.second <= dis[i.first])
			{
				dis[i.first] = dis[now] + i.second;
				q.push({i.first,dis[i.first]});
				//cout << now << "->" << i.first << endl;
			}
		}
	}
	return dis[to];
}

signed main()
{
	//1~n站厅
	//第i条地铁线路候车处 (i+1)*t 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(long long i = 1;i<=m;i++)cin >> w[i];
	if(1 <= c && c <= 6)
	{
		for(long long i = 1;i<=n;i++)
		{
			cin >> k[i];
			long long t1 = 0,t4 = 0;
			cin >> t1 >> t4;
			g[t1].push_back({i*m+t1,t4});
			g[i*m+t1].push_back({t1,t4});
			for(long long j = 2;j<=k[i];j++)
			{
				long long t2,t3;
				cin >> t2 >> t3;
				g[i*m+t1].push_back({i*m+t2,0});
				g[i*m+t2].push_back({i*m+t1,0});
				g[t2].push_back({i*m+t2,t3});
				g[i*m+t2].push_back({t2,t3});
				t1 = t2;
			}
		}
		while(q--)
		{
			long long x1,x2;
			cin >> x1 >> x2;
			cout << w[x1] + djsk(x1,x2) + w[x2] << endl;
		}
	}
	else if(7 <= c && c <= 11)
	{
		memset(spfa,0x3f,sizeof spfa);
		for(long long i = 1;i<=n;i++)
		{
			cin >> k[i];
			if(k[i] == 1)
			{
				long long t1,t2;
				cin >> t1 >> t2;
				continue;
			}
			else 
			{
				long long t1,t2,t3,t4;
				cin >> t1 >> t2 >> t3 >> t4;
				g[t1].push_back({t3,t2+t4});
				g[t3].push_back({t1,t2+t4});
				spfa[t1][t3] = t2+t4;
				spfa[t3][t1] = t2+t4;
			}
		}
		//spfa
		for(long long k = 1;k<=n;k++)
			for(long long i = 1;i<=n;i++)
				for(long long j = 1;j<=n;j++)
					spfa[i][j] = min(spfa[i][j],spfa[i][k] + spfa[k][j]);
		while(q--)
		{
			long long l,r;
			cin >> l >> r;
			cout << spfa[l][r] + w[l] + w[r] << endl;
		}
	}
	return 0;
 } 
 //32pts 
