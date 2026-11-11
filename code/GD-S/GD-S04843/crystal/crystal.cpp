#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
const int INF = 0x3f3f3f3f;
int a [N] , n , m , c [N] , len;
signed main()
{
		freopen ("crystal.in" , "r" , stdin);
		freopen ("crystal.out" , "w" , stdout);
		scanf ("%lld %lld" , &n , &m);
		for (int i = 1; i <= n; i++) scanf ("%lld" , &a [i]); 
		sort (a + 1 , a + n + 1);
		for (int i = 2; i <= n; i++) c [i] = a [i] - a [i - 1];
		for (int i = 1; i <= n; i++)
		{
			int r = i + 1 , sum = m;
			if (n - i + 1 <= len) break; 
			while (r <= n && sum - c [r] * (r - i) >= 0)
			{
				sum -= c [r] * (r - i);
				r++;
			}
			len = max (len , r - i);
		}
			//for (int i = 1; i <= n; i++) printf ("%lld " , c [i]); 
		cout << len;
		return 0;
}
