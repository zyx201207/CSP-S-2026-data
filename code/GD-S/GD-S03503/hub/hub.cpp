#include <bits/stdc++.h>
using namespace std;
int c,t,dis[100010];
vector<int> g[10010];
int n,k;
void bfs(int s)
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int d[100010];
	bool v[100010];
	queue<int> q;
	q.push(s);
	d[s] = 0;
	v[s] = true;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		v[x] = false;
		for(int i = 0 ; i < g[x].size() ; i ++)
		{
			int y = g[x][i];
			if(d[y] > d[x]+1)
			{
				d[y] = d[x] +1;
				if(v[y] == false)
				{
					q.push(y);
					v[y] = true;
				}
			}
		}
	}
	for(int i = 1 ; i <= n ; i ++) dis[i] = min(dis[i],d[i]);
}
int ans = 0;
void  dfs(int i,int num)
{
	if(i == n) return ;
	if(num == k)
	{
		int cnt =0 ;
		for(int i = 1 ; i <= n ; i ++) cnt = max(cnt,dis[i]);
		ans = max(ans,cnt);
		return ;
	}
	dfs(i+1,num);
	bfs(i);
	dfs(i+1,num+1);
}
int main()
{
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1 ; i < n ; i ++)
		{
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		cout << ans << "\n";
	}
}
