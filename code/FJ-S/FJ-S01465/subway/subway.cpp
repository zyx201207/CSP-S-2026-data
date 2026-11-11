#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x;
}

struct substop
{
	int w, t[501] = {};
	bool x[501] = {};
	void prints(int k)
	{
		x[k] = true;
		t[k] = read();
	}
}stop[500001];

struct subline
{
	int k, a[500001];
	void print()
	{
		k = read();
		for (int i = 1;i <= k;i++)
		{
			a[i] = read();
			stop[a].prints(k);
		}
	}
	
}line[501];

bool flags[500001], flagl[501];

int c, n, m, d, q, x, y;
long long dfs(int xy, long long ans)
{
	if(xy == y) return ans;
	long long minn = 500000000000000;
	for (int i = 1;i <= n;i++)
	{
		if(!flagl[i] && stop[xy].x[i])
		{
			flagl[i] = true;
			for(int j = 1;j <= line[i].k;j++)
			{
				if(!flags[line[i].a[j]])
				{
					flags[line[i].a[j]] = true;
					minn = min(minn, dfs(i, ans + stop[xy].t[i] + stop[j].t[i]));
					flags[line[i].a[j]] = false;
				}
			}
			flagl[i] = false;
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cout.tie(0);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1;i <= m;i++) stop[i].w = read();
	for (int i = 1;i <= n;i++) line[i].print();
	
	for (int i = 1;i <= q;i++)
	{
		x = read(), y = read();
		cout << dfs(x, 0) + stop[x].w + stop[y].w << endl;
	}
	return 0;
 } 
