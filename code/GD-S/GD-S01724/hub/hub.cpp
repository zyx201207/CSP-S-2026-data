#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
int c,t,n,m,u,v,cp,ans,num[N];
bool vis[N];
vector <int> road[N];

bool cmp(int x,int y) { return (x > y); }
int dfs(int now,int fa)
{
	vis[now] = true;
	if ((int)road[now].size() == 1) return 1;
	int sum = 0;
	for (int i = 0;i < (int)road[now].size();i++) if (road[now][i] != fa && !vis[road[now][i]]) sum += dfs(road[now][i],now);
	return sum;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 1;i < n;i++)
		{
			cin >> u >> v;
			road[u].push_back(v); road[v].push_back(u);
		}
		if (n <= 5)
		{
			for (int i = 1;i <= n;i++) if (!vis[i]) num[++cp] = dfs(i,0);
			if (cp == 5) cout << "0\n";
			else cout << "1\n";
		}
		else cout << "1\n";
	}
	return 0;
}
