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

const int N = 1e7 + 10;
int n, a[N], tot = 0;
long long ans = 0, sum = 0;

int main ()
{
    freopen ("string.in", "r", stdin);
    freopen ("string.out", "w", stdout);
    n = read ();
    for (int i = 1; i <= n; i ++)
    {
		int x = read ();
		char c = getchar ();
		getchar ();
		sum += x;
		for (int j = 1; j <= x; j ++) a[++ tot] = c - 'a';
	}
	
	for (int i = 1; i + i <= sum ; i ++)
        if (a[i] != a[sum - i + 1]) ans ++;
        
    printf ("%lld", ans);
	
    return 0;
}
