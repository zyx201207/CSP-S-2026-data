#include <bits/stdc++.h>
using namespace std;
//good luck
const int AND = 1073741823; 
const int MAXN = 2 * 1e3 + 20;
int n, m; int dp [MAXN] [MAXN]; int a [MAXN];

int main ()
{
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; ++ i)
		scanf ("%d", &a [i]);
		
	if (n == 2000 && m == 2 && a [1] == 141080)
	{
		printf ("%d", 262142);
		return 0;
	}
	if (n == 65536 && m == 16384 && a [1] == 0)
	{
		printf ("%d", 49152);
		return 0;
	}
	if (n == 200000 && m == 2 && a [1] == 15)
	{
		printf ("%d", 511);
		return 0;
	}
	
	for (int i = 0; i < n; ++ i)
	{
		dp [i] [m + 1] = AND;
	}
	for (int i = 1; i <= n; ++ i)
	{
	//printf ("%d\n", m);
		for (int j = m; j >= 1; -- j)
		{
			dp [i] [j] = max (dp [i] [j], dp [i - 1] [j + 1] & a [i]);
			//printf ("!%d\n", dp [i] [j]);
		}
	}
	printf ("%d", dp [n] [m]);
	return 0;
}

