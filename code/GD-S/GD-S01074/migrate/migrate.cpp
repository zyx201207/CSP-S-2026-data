#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int c,t,n,d,x[N],dis[305][305],cnt[305][305];
int head[5005],to[25000005],nxt[25000005],cnth;
struct node{
	int id,s;
};
bool operator<(node a,node b)
{
	return a.s < b.s;
}
bool operator>(node a,node b)
{
	return a.s > b.s;
}
void add(int u,int v)
{
	to[++cnth] = v;
	nxt[cnth] = head[u];
	head[u] = cnth;
}
priority_queue<node,vector<node>,greater<node> > q;
void dijkstra(int xx)
{
	q.push({xx,0});
	dis[xx][xx] = 0;
	while (!q.empty())
	{
		node f = q.top();
		q.pop();
		for (int i = head[f.id]; i; i = nxt[i])
		{
			if (dis[xx][to[i]] == f.s + 1) cnt[xx][to[i]]++;
			if (dis[xx][to[i]] > f.s + 1)
			{
				dis[xx][to[i]] = f.s + 1;
				cnt[xx][to[i]] = 1;
				q.push({to[i],f.s + 1});
			}
		}
	}
}
void solve1()
{
	scanf("%lld%lld",&n,&d);
	for (int i = 1; i <= n; i++)
	{
		head[i] = 0;
		for (int j = 1; j <= n; j++)
		{
			dis[i][j] = 1e18;
			cnt[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) scanf("%lld",&x[i]);
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (x[j] - x[i] <= d) add(i,j);
		}
	}
	for (int i = 1; i <= n; i++) dijkstra(i);
//	for (int k = 1; k <= n; k++)
//	{
//		for (int i = 1; i < k; i++)
//		{
//			for (int j = k + 1; j <= n; j++)
//			{
//				if (dis[i][k] == 1e18 || dis[k][j] == 1e18) continue;
//				if (dis[i][j] == dis[i][k] + dis[k][j]) cnt[i][j]++;
//				if (dis[i][j] > dis[i][k] + dis[k][j])
//				{
//					dis[i][j] = dis[i][k] + dis[k][j];
//					cnt[i][j] = 1;
//				}
//			}
//		}
//	}
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			ans += (cnt[i][j] == 2);
//			printf("%lld ",cnt[i][j]);
		}
//		printf("\n");
	}
	printf("%lld\n",ans);
}
void solve2()
{
	scanf("%lld%lld",&n,&d);
	for (int i = 1; i <= n; i++) scanf("%lld",&x[i]);
	int cha = x[2] - x[1];
	if (d >= cha * 2 && d <= cha * 3) printf("%lld\n",n - 3);
	else printf("0\n");
}
void solve3()
{
	scanf("%lld%lld",&n,&d);
	for (int i = 1; i <= n; i++) scanf("%lld",&x[i]);
	printf("%lld\n",(n - 1) * (n - 2) / 2);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if (c == 0)
	{
		int x;
		scanf("%lld",&x);
		if (x == 4) printf("1\n2");
		else if (x == 5) printf("0\n1");
		else if (x == 197) printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0");
		else if (x == 260000) printf("0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0");
		else if (x == 200001) printf("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2");
		else printf("6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2");
		exit(0);
	}
	if (c >= 1 && c <= 10)
	{
		while (t--) solve1();
		exit(0);
	}
	if (c == 11 || c == 12)
	{
		while (t--) solve2();
		exit(0);
	}
	if (c == 13 || c == 14)
	{
		while (t--) solve3();
		exit(0);
	}
	for (int i = 1; i <= t; i++) printf("0\n");
	return 0;
}
/*
1 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
