#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 3,INF = 1e9;
int c,n,m,d,q,u,v,ans,a[N],l[N],b[N][N],t[N][N];

void dfs(int now,int sum)
{
	if (now == v)
	{
		ans = min(ans,sum);
		return ;
	}
	for (int i = 1;i <= n;i++) for (int j = 1;j <= l[i];j++) if (b[i][j] == now)
	{
		for (int k = j + 1;k <= l[i];k++) dfs(b[i][k],sum + t[i][j] + t[i][k]);
		break;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> a[i];
	for (int i = 1;i <= n;i++)
	{
		cin >> l[i];
		for (int j = 1;j <= l[i];j++) cin >> b[i][j] >> t[i][j];
	}
	while (q--)
	{
		cin >> u >> v;
		ans = INF;
		dfs(u,0);
		cout << ans + a[u] + a[v] << "\n";
	}
	return 0;
}
