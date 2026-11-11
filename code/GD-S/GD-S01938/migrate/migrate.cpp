#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5,Maxn = 2e7 + 5;
struct edge
{
	int nxt,to;
}e[Maxn];
int head[MAXN],tot;
inline void merge(int u,int v)
{
	e[++tot] = (edge){head[u],v},head[u] = tot;
}
long long x[MAXN],D;
int que[MAXN],dis[MAXN],cnt[MAXN],n;
inline void spfa(int st)
{
	int l = 1,r = 0,u,v;
	que[++r] = st;
	for (int i = 1; i <= n; i++) dis[i] = cnt[i] = 0;
	cnt[st] = 1;
	while (l <= r)
	{
		u = que[l++];
		for (int i = head[u]; i; i = e[i].nxt)
		{
			v = e[i].to;
			if (!dis[v]) que[++r] = v,dis[v] = dis[u] + 1,cnt[v] = cnt[u];
			else if (dis[v] == dis[u] + 1) cnt[v] += cnt[u];
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	long long ans;
	cin >> C >> T;
	while (T--)
	{
		tot = ans = 0;
		cin >> n >> D;
		for (int i = 1; i <= n; i++) cin >> x[i],head[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (abs(x[i] - x[j]) > D) break;
				merge(i,j);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			spfa(i);
			for (int j = i + 2; j <= n; j++) if (cnt[j] == 2) ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
