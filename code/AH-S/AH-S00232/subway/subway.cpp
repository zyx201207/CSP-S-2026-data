#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 * 5 + 10;
const int INF = 0x3f3f3f3f;
priority_queue < pair<int, int> > q;
int c, n, m, D, Q, pla[N];
int head[N], Next[N], ver[N], edge[N], tot = 0;
int d[N];
bool v[N];

inline int read ()
{
	int x = 0;
	bool f = 0;
	char c = getchar ();
    for (; c < '0' || c > '9'; c = getchar ()) if (c == '-') f = 1;
    for (; c >= '0' && c <= '9'; c = getchar ())
       x = x * 10 + c - '0';
    return f? -x : x;
}

void dijkstra (int s)
{
	memset (v, 0, sizeof v);
	memset (d, INF, sizeof d);
	q.push ({0, s});
	d[s] = 0;
	while (!q.empty ())
	{
		int x = q.top ().second; q.pop ();
		if (v[x]) continue;
		v[x] = 1;
		for (int i = head[x]; i; i = Next[i]) 
		{
			int y = ver[i], z = edge[i];
			if (d[y] > d[x] + z) 
			{
				d[y] = d[x] + z;
				q.push ({-d[y], y});
			}
		}
	}
	return ;
}


void add (int x, int y, int z)
{
    ver[++ tot] = y, edge[tot] = z;
    Next[tot] = head[x], head[x] = tot;
    return ;
}


int main ()
{
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    c = read (), n = read (), m = read (), D = read (), Q = read ();
    for (int i = 1; i <= m; i ++) pla[i] = read();
    for (int i = 1; i <= n; i++ )
    {
		read ();
		for (int j = 1; j <= 2; j ++)
		{
			int x = read (), a = read (), y = read (), b = read ();
			add (x, y, b);
			add (y, x, a);
		}
	}
	
	for (int i = 1; i <= Q; i ++)
	{
		int x = read(), y = read();
		dijkstra (x);
		printf ("%d\n", d[y] + pla[x] + pla[y]);
	}
	
    return 0;
}
