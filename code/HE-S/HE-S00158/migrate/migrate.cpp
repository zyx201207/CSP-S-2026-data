#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],dis[2000005],cnt = 0,l,u,w,v;
vector<pair<long long,long long>> e[2000005];
bool vis[2000005];
priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
bool DJSTL(long long S,long long T)
{
	long long minn = LLONG_MAX,cnt = 1;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[S] = 0;
	q.push({0,S});
	while (!q.empty())
	{
		l = q.top().first;
		u = q.top().second; 
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (long long i = 0;i < e[u].size();i++)
		{
			w = e[u][i].second;
			v = e[u][i].first;
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				q.push({dis[v],v});
			}
			if (v == T)
			{
				if (dis[v] < minn)
				{
					minn = dis[v];
					cnt = 1;
				}
				else if (dis[v] == minn)
				{
					cnt++;
				}
			}
		}
	}
	return cnt == 2; 
}
int main()
{
	// 快读 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// 主代码 
	cin>>c>>t;
	while (t--)
	{
		cnt = 0;
		for (long long i = 1;i <= n;i++) e[i].clear();
		cin>>n>>d;
		for (long long i = 1;i <= n;i++) cin>>x[i];
		for (long long i = 1;i <= n - 1;i++)
		{
			for (long long j = i + 1;j <= n;j++)
			{
				if (abs(x[i] - x[j]) <= d)
				{
					e[i].push_back({j,1});
					e[j].push_back({i,1});
				}
			}
		} //建图 
		for (long long i = 1;i <= n - 1;i++)
		{
			for (long long j = i + 1;j <= n;j++)
			{
				if (DJSTL(i,j)) cnt++;
			}
		} // 计算答案 
		cout<<cnt<<'\n';
	}
	return 0;
}
