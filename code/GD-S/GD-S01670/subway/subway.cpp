#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read();
const int N = 5e5 + 10;
struct node{
	int a, t;
};
vector<node> e[N];
vector<int> num[N];
int w[N];
bool vis[N];
int ans = 1e9;

void dfs(int st, int end, int len)
{
	if(st == end)
	{
		ans = min(ans, len);
		printf("%d OK\n", len);
		return ;
	}
	for(int u : num[st])
	{
		int rem = 0;
		for(node nxt : e[u])
		{
			if(nxt.a == st)
			{
				rem = nxt.t;
				break;
			}
		}
		for(node nxt : e[u])
		{
			if(vis[nxt.a] || nxt.a == st) continue;
			vis[nxt.a] = 1;
			//printf("%d->%d\n", st, nxt.a);
			int rem = 0;
			dfs(nxt.a, end, len + nxt.t + rem);
			//printf("%d<-%d\n", nxt.a, st);
			vis[nxt.a] = 0;
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c = read(), n = read(), m = read(), d = read(), q = read();
	for(int i = 1; i <= m; i++) w[i] = read();
	for(int i = 1; i <= n; i++)
	{
		int k = read();
		for(int j = 1; j <= k; j++)
		{
			int pl = read(), tim = read();
			e[i].push_back({pl, tim});
			num[pl].push_back(i);
		}
	}
	/*if(n <= 2)
	{
		int minn = 1e6;
		for(int i = 1; i <= n; i++)
		{
			int min1 = 1e6, min2 = 1e6;
			for(node nxt : e[i])
			{
				if(nxt.a == 1) min1 = min(min1, nxt.t);
				if(nxt.a == 2) min2 = min(min2, nxt.t);
			}
			minn = min(minn, min1 + min2);
		}
		while(q--) printf("%d\n", minn + w[1] + w[2]);
		return 0;
	}*/
	while(q--)
	{
		int x = read(), y = read();
		ans = 1e9;
		int st = w[x] + w[y];
		dfs(x, y, 0);
		printf("%lld\n", ans + st);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
ans:
35
16
*/
inline ll read()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
