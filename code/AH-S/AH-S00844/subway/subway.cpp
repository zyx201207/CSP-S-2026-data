#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
long long C,n,m,d,q,w[25];
long long pq[505][25][25],vis[25],diff[25];
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > b;
void dij(long long s,long long e)
{
	b.push({s,0});
	diff[s] = 0;
	while (!b.empty())
	{
		pair<long long,long long> csn = b.top();
		b.pop();
		long long fr = csn.first,sd = csn.second;
		if (vis[fr])
		{
			continue;
		}
		vis[fr] = 1;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= m;j++)
			{
				if (diff[j] > sd + pq[i][fr][j])
				{
					diff[j] = sd + pq[i][fr][j];
					b.push({j,pq[i][fr][j]});
				}
			}
		}
	}
	cout << diff[e] << endl;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(pq,inf,sizeof(pq));
	cin >> C >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++)
	{
		vector<int> u;
		int nu;
		cin >> nu;
		for (int j = 1;j <= nu;j++)
		{
			int a,t;
			cin >> a >> t;
			u.push_back(a);
			for (int k = 0;k < int(u.size());k++)
			{
				pq[i][u[k]][a] = t;
				pq[i][a][u[k]] = t;
			}
		}
	}
	for (int i = 1;i <= q;i++)
	{
		memset(vis,0,sizeof(vis));
		memset(diff,inf,sizeof(diff));
		long long s,e;
		cin >> s >> e;
		dij(s,e);
	}
}
