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

const int N = 1e5 * 2 + 10;
int n, m, a[N], num[N];
long long ans = -1;

void dfs (int t, int k, int now)
{
	if (k == 0) 
    {
		long long sum = a[num[1]];
		for (int i = 2; i <= m; i ++) sum &= a[num[i]];
		ans = max (ans, sum);
		return ;
	}
	for (int i = now; i <= n - k + 1; i ++) 
	{
		num[t] = i;
		dfs (t + 1, k - 1, i + 1);
	}
	return ;
}

int main ()
{
    freopen ("and.in", "r", stdin);
    freopen ("and.out", "w", stdout);
    n = read ();
    m = read ();
    if (n >= 2 * 1e5) {putchar ('1'); return 0;}
    for (int i = 1; i <= n; i ++) a[i] = read ();
    dfs (1, m, 1);
    printf ("%lld", ans);
    return 0;
}
