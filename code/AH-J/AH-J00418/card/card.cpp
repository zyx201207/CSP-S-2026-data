#include <bits/stdc++.h>
using namespace std;
inline int read ()
{
	int x = 0;
	char c = getchar ();
	bool f = 0;
	for (; c < '0' || c > '9'; c = getchar ()) 
	   if (c == '-') f = 1;
	for (; c >= '0' && c <= '9'; c = getchar ()) 
	   x = x * 10 + c - '0';
	return f ?  -x : x;
}

const int N = 1e5 * 5 + 10;
int n, m, a[N], desk[N], tot = 0, t[N];

int search (int x)
{
	for (int i = 1; i <= tot; i ++) if (desk[i] == x) return i;
	return 0;
}

int main ()
{
    freopen ("card.in", "r", stdin);
    freopen ("card.out", "w", stdout);
    n = read ();
    m = read ();
    for (int i = 1; i <= n; i ++) a[i] = read ();
    
    for (int i = 1; i <= n; i ++)
    {
		memset (desk, 0, sizeof desk);
		for (int j = i; j <= n; j ++)
		{
			int x = search (a[j]);
			if (x) tot = x;
			else desk[++ tot] = a[j];
		}
		for (int j = 1; j <= m; j ++)
		   if (search (j)) t[j] ++;
	}
	
	for (int i = 1; i <= m; i ++) printf ("%d ", t[i]);
    
    return 0;
}
