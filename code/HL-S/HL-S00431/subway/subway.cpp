#include <iostream>
#include <cstdio>

using namespace std;

int c, n, m, d, q;
int w[500010];
int k;
int a, t;
int x, y;

int Next[500010], Head[500010], to[500010], val[500010], cnt;

long long mint[510][510];

void add(int a, int b, int c)
{
	to[ ++ cnt] = b;
	val[cnt] = c;
	Next[cnt] = Head[a];
	Head[a] = cnt;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= n; j ++ )
			if(i != j) mint[i][j] = 2147483647;
	
	for(int i = 1; i <= m; i ++ ) scanf("%d", &w[i]);
	
	for(int i = 1; i <= n; i ++ )
	{
		scanf("%d", &k);
		
		for(int j = 1; j <= k; j ++ )
		{
			scanf("%d %d", &a, &t);
			add(a, i, t);
			for(int p = Head[a]; p; p = Next[p])
			{
				int f = to[p];
				if(mint[f][i] > val[p] + t)
				{
					mint[f][i] = val[p] + t;
					mint[i][f] = val[p] + t;
				}
			}
		}
	}
	
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= n; j ++ )
			for(int p = 1; p <= n; p ++ )
				mint[i][p] = min(mint[i][p], mint[i][j] + mint[j][p]);

	while(q -- )
	{
		cin >> x >> y;
		long long ans = 2147483647;
		
		for(int i = Head[x]; i; i = Next[i])
		{
			for(int j = Head[y]; j; j = Next[j])
			{
				int f1 = to[i], f2 = to[j];
				ans = min(ans, mint[f1][f2] + val[i] + val[j] + w[x] + w[y]);
			}
		}
		
		printf("%lld\n", ans);
	}
	return 0;
}