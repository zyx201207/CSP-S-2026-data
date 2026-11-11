#include <cstring>
#include <iostream>

#define int long long

using namespace std;

const int N = 2000010, M = 5010;

int n, m;
int dist[N];
bool sign[M];
int q[N], hh, tt = -1;
int d[M][M], cnt[M][M];
int h[N], e[N], ne[N], idx;

inline void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

inline void bfs(int start)
{
	hh = 0, tt = -1;
	
	memset(sign, 0, sizeof sign);
	
	q[ ++ tt ] = start;
	sign[start] = true;
	cnt[start][start] = 1;
	d[start][start] = 0;
	
	while (hh <= tt)
	{
		int t = q[hh ++ ];
		
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			
			if (d[start][j] > d[start][t] + 1)
			{
				d[start][j] = d[start][t] + 1;
				cnt[start][j] = cnt[start][t];
			}
			else if (d[start][j] == d[start][t] + 1)
				cnt[start][j] += cnt[start][t];
			
			if (!sign[j])
			{
				sign[j] = true;
				q[ ++ tt ] = j;		
			}
		}
	}
}

inline int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	
	return x * f;
}

inline void write(int x)
{
	if (x < 0)
	{
		x = -x;
		putchar('-');
	}
	
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c = read(), cases = read();
	
	while (cases -- )
	{
		memset(h, -1, sizeof h);
		memset(d, 0x3f, sizeof d);
		memset(cnt, 0, sizeof cnt);
		
		n = read(), m = read();
		for (int i = 1; i <= n; ++ i )
			dist[i] = read();
		
		if (n <= 5000)
		{
			for (int i = 1, j = 1; i <= n; ++ i )
			{
				while (j < n && dist[j + 1] - dist[i] <= m)
					j ++;
				for (int k = i + 1; k <= j; ++ k )
					add(i, k);
			}
			
			for (int i = 1; i <= n; ++ i )
				bfs(i);
			
			int res = 0;
			for (int i = 1; i <= n; ++ i )
				for (int j = i + 1; j <= n; ++ j )
					if (cnt[i][j] == 2) res ++ ;
		
//			for (int i = 1; i <= n; ++ i )
//				for (int j = 1; j <= n; ++ j )
//					write(cnt[i][j]), putchar(j == n ? '\n' : ' ');
			
			write(res), putchar('\n');
		}
		else
		{
			for (int i = 1, j = 1; i <= n; ++ i )
			{
				while (j < n && dist[j + 1] - dist[i] <= m)
					j ++ ;
				for (int k = i + 1; k <= j; ++ k )
					add(i, k);
			}
			
			bfs(1);
			
			int res = 0;
			for (int i = 1; i <= n; ++ i )
				if (d[1][i] == 2)
				{
					res += n - i + 1;
				}
			
			write(res), putchar('\n');
		}
	}
	
	return 0;
}
