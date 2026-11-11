#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int change[600][600];
int ans (int s,int e)
{
	int dist[n + 1] = {};
	for (int i = 0; i <= n; i++) dist[i] = -1;
	bool vis[n + 1] = {};
	dist[s] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({0,s});
	while (!q.empty())
	{
		int u = q.top().second;
		int v = q.top().first;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int k = 1; k <= n; k++) {
			if (change[u][k] == -1) continue;
			if (dist[k] == -1 || dist[k] > v + change[u][k]) {
				dist[k] = v + change[u][k];
				q.push({dist[k],k});
			}
		}
	}
	return dist[e];
}

int main ()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	int w[m + 1];
	int a[n + 1][m + 1],t[n + 1][m + 1];
	memset (w,0,sizeof(w));
	memset (a,0,sizeof(w));
	memset (t,0,sizeof(w));
	for (int i = 1; i <= m; i++) cin >> w[i];
	
	vector<int> trans[m + 1];
	for (int i = 0; i <= 500; i++)
		for (int j = 0; j <= 500; j++)
			change[i][j] = -1;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i][0];
		for (int j = 1; j <= a[i][0]; j++) {
			cin >> a[i][j] >> t[i][j];
			trans[a[i][j]].push_back(i);
		}
	}
	
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < trans[i].size(); j++)
			for (int k = j + 1; k < trans[i].size(); k++)
			{
				int t1 = t[trans[i][j]][i] + t[trans[i][k]][i];
				if (change[j][k] > t1 || change[j][k] == -1) change[j][k] = change[k][j] = t1;
			}
	}
	
	while (q--)
	{
		int x,y;
		cin >> x >> y;
		int tmp = w[x] + w[y];
		int sum = 1e8;
		for (int i = 1; i <= trans[x].size(); i++)
			for (int j = 1; j <= trans[y].size(); j++)
				sum = min (sum,ans(trans[x][i],trans[y][j]) + t[trans[x][i]][x] + t[trans[y][j]][y]);
		cout << sum + tmp << endl;
	}
	return 0;
}