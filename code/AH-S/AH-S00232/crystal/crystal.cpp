#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read ()
{
	int x = 0;
	bool f = 0;
	char c = getchar ();
    for (; c < '0' || c > '9'; c = getchar ()) if (c == '-') f = 1;
    for (; c >= '0' && c <= '9'; c = getchar ())
       x = x * 10 + c - '0';
    return f? -x : x;
}

const int N = 1e5 * 5 + 10;
int n;
ll m, a[N], b[N], ans = -1, s[N];

int main ()
{
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    
    scanf ("%d", &n);
    m = read ();
    for (int i = 1; i <= n; i ++) a[i] = read ();
	sort (a + 1, a + 1 + n);
	for (int i = 2; i <= n; i ++) s[i] = s[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	for (ll i = 1; i <= n; i ++)
	{
		if (s[i] <= m) 
	    {
			ans = max (ans, i);
			continue ;
		}
		int l = 1, r = n;
		while (l <= r)
		{
			ll x = (l + r) >> 1;
			ll temp = s[i] - s[x] - (a[i] - a[x]) * (x - 1);
			if (temp <= m) l = x + 1, ans = max (ans, i - x + 1);
			else r = x - 1;
		}
	}
	
	printf ("%lld", ans);
    
    return 0;
}
