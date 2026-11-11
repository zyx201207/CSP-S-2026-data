#include <bits/stdc++.h>

using namespace std;

#define int long long

int c, n, m, d, Q;
int k[510];
int a[510][50010];
int t[510][50010];
int w[500010];
vector <int> v[500010];
int visf[510][5010];
int val[510][5010];
int dp[5050][5050], T;
int W[5050][5050];
int vi[5010] = {0};

struct node
{
	int l, r;
}q[100010];

void dfs(int l, int p, int cnt)
{
	W[l][p] = min(W[l][p], cnt);
	for(int i = 0; i < v[p].size(); i ++)
	{
		int x = v[p][i];
		for(int j = 1; j <= k[x]; j ++)
		{
			if(a[x][j] == p) continue;
			if(vi[a[x][j]]) continue;
			vi[a[x][j]] = 1;
			dfs(l, x, cnt + val[x][p] + val[x][a[x][j]]);
			vi[a[x][j]] = 0;
		}
	}
}


void solve1()
{
	for(int i = 1; i <= m; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			W[i][j] = 1e8;
			for(int o = 1; o <= n; o ++)
			{
				if(visf[o][i] && visf[o][j])
				{
					W[i][j] = min(W[i][j], val[o][i] + val[o][j]);
				}
			}
		}
	}
	for(int i = 1; i <= m; i ++)
	{
		vi[i] = 1;
		dfs(i, i, 0);
		vi[i] = 0;
	}
	for(int i = 1; i <= Q; i ++)
	{
		int L = q[i].l;
		int R = q[i].r;
		cout << w[L] + w[R] + W[L][R] << '\n';
	}
}

void solveA()
{
	int vis[5050][5050] = {0};
	for(int i = 1; i <= m; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			vis[i][j] = 0;
			dp[i][j] = 1e18;
		}
		dp[i][i] = 0;
	}
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= k[i]; j ++)
		{
			for(int K = 1; K <= k[i]; K ++)
			{
				dp[a[i][j]][a[j][K]] = 0;
			}
		}
		dp[a[i][1]][a[i][2]] = dp[a[i][2]][a[i][1]] = t[i][1] + t[i][2];
	}
	for(int k = 1; k <= m; k ++)
	{
		for(int i = 1; i <= m; i ++)
		{
			for(int j = 1; j <= m; j ++)
			{
				if(i == j) continue;
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	for(int i = 1; i <= Q; i ++)
	{
		int L = q[i].l;
		int R = q[i].r;
		cout << w[L] + w[R] + dp[L][R] << '\n';
	}
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1; i <= m; i ++)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= 3; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			val[i][j] = 1e18;
		}
	}
	for(int i = 1; i <= n; i ++)
	{
		cin >> k[i];
		if(k[i] == 1) continue;
		for(int j = 1; j <= k[i] * 2; j ++)
		{
			if(j&1)
			{
				cin >> a[i][(j + 1) / 2];
				v[a[i][(j + 1) / 2]].push_back(i);
				visf[i][a[i][(j + 1) / 2]] = 1;
			}
			else
			{
				cin >> t[i][j / 2];
				T = t[i][j / 2];
				val[i][a[i][j / 2]] = t[i][j / 2];
			}
		}
	}
	for(int i = 1; i <= Q; i ++)
	{
		cin >> q[i].l >> q[i].r;
	}
	if(c >= 7 && c <= 11) solveA();
	else solve1();
	return 0;
}
