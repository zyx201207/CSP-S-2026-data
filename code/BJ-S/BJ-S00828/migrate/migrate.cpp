#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
const int INF = 2e6 + 5;
int c,t;
long long n,d,a[maxn];
vector<int> v[maxn];
int vis[maxn],dis[maxn];
void bfs(int x)
{
	queue<int> q;
	for(int i = 1;i <= n;i++) vis[i] = INF,dis[i] = 0;
	q.push(x);vis[x] = 0,dis[x] = 1;
	while(!q.empty())
	{
		int u = q.front();q.pop();
		for(int i : v[u])
		{
			if(i == u || vis[u] + 1 > vis[i]) continue;
			if(vis[u] + 1 == vis[i]) dis[i] += dis[u];
			else
			{
				vis[i] = vis[u] + 1;
				dis[i] = 1;
				q.push(i);
			}
		}
	}
	/*for(int i = 1;i <= n;i++) cout << vis[i] << " ";
	cout << endl;
	for(int i = 1;i <= n;i++) cout << dis[i] << " ";
	cout << endl;*/
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		memset(v,0,sizeof v);
		for(int i = 1;i <= n;i++) cin >> a[i];
		sort(a + 1,a + 1 + n);
		for(int i = 1;i <= n;i++)
		{
			for(int j = i - 1;j >= 1;j--)
				if(a[i] - a[j] <= d || j == i - 1) {v[i].push_back(j);v[j].push_back(i);}
		}
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			bfs(i);
			for(int j = i + 2;j <= n;j++)
			{
				if(dis[j] == 2) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
