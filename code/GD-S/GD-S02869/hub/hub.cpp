#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

#define ll long long

const int MAXN = 1e6 + 7;
const int MAXK = 1e6 + 7;

int c, t;

bool in_S[MAXN];
int S[MAXK];

std::vector<int> nxts[MAXN];
bool vis[MAXN];

void flood(int q)
{
	vis[q] = true;
	
	for (int i = 0; i < nxts[q].size(); i++)
	{
		int v = nxts[q][i];
		if (in_S[v] && !vis[v]) flood(v);
	}
}

bool check(ll k, ll n)
{
	memset(vis, 0, sizeof vis);
	
	int cnt = 0;
	for (int i = 1; i <= k; i++)
	{
		if (!vis[S[i]])
		{
			if (cnt == 2) return false;
			cnt++;
			flood(S[i]);
		}
	}
	
	return true;
}

ll calc()
{
	
}

void dfs(int q, int l, ll k, ll n)
{
	if (l == k)
	{
		if (!check(k, n)) return;
		
	}
}

int main()
{
	std::cin >> c >> t;
	
	while (t--)
	{
		ll n, k;
		std::cin >> n >> k;
		for (int i = 1; i <= n - 1; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			nxts[u].push_back(v);
			nxts[v].push_back(u);
		}
	}
}
