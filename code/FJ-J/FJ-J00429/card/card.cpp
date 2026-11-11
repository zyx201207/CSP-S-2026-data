#include <bits/stdc++.h>
using namespace std;

int s[500005];
int vis[300005];
int ans[300005];
int n, m;

void play(int st, int s_t[500005])
{
	memset(vis, 0, sizeof(vis));
	for(int i=st ; i<=n ; i++)
	{
		if(vis[s_t[i]] != 0)
		{
			for(int j=vis[s_t[i]] ; j<i ; j++)
			{
				vis[s_t[j]] = 0;
			}
		}
		vis[s[i]] = i;
	}
	for(int i=1 ; i<=m ; i++)
	{
		if(vis[i]) ans[i]++;
	}
}

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i=1 ; i<=n ; i++)
	{
		cin >> s[i];
	}
	for(int i=1 ; i<=n ; i++)
	{
		play(i, s);
	}
	for(int i=1 ; i<=m ; i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
