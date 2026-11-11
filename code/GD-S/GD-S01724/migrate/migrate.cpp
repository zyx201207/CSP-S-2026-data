#include <bits/stdc++.h>
using namespace std;
const int N = 303,INF = 1e9;
int c,q,n,m,ans,sum,sta,a[N],deep[N];
vector <int> road[N];

void dfs(int now,int dep,int fa)
{
	deep[now] = dep;
	for (int i = 0;i < road[now].size();i++) if (deep[road[now][i]] > dep + 1 && road[now][i] != fa) dfs(road[now][i],dep + 1,now);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> q;
	while (q--)
	{
		cin >> n >> m;
		ans = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
			road[i].clear();
		}
		sort(a + 1,a + n + 1);
		for (int i = 1;i <= n;i++) for (int j = i + 1;j <= n;j++) if (a[j] - a[i] <= m) { road[i].push_back(j); road[j].push_back(i); }
		for (int i = 1;i <= n;i++)
		{
			dfs(i,1,0);
			for (int j = 1;j <= n;j++)
			{
				sum = 0;
				for (int l = 0;l < (int)road[j].size();l++) if (deep[road[j][l]] + 1 == deep[j]) sum++;
				if (sum == 2) ans++;
			}
			for (int j = 1;j <= n;j++) deep[j] = INF;
		}
		cout << ans / 2 << "\n";
	}
	return 0;
}
