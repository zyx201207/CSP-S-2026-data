#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

const long long N = 2 * 1e+5 + 10;
long long aa[N], ans, n, m, x, y;
char ab[N];
bool flag = true;
string s = "";
int main ()
{
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	scanf ("%lld", &n);
	m = n;
	for (int i = 1;i <= n; i++)
	{
		scanf ("%lld %c", &aa[i], &ab[i]);
		if (ab[i - 1] == ab[i]) aa[i - 1] += aa[i], m--;
	}
	if (m == 1) 
	{
		cout << 0; 
		return 0;
	}
	for (int i = 1; i <= n; i++){
		if (ab[i] == ab[i + 1])
		{
			for (int j = i + 1; j < n; j++) aa[j] = aa[j + 1], ab[j] = ab[j + 1];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (!(aa[i] == aa[m + 1 - i] && ab[i] == ab[m + 1 - i]))
		{
			flag = false;
			break;
		}
	}
	if (flag == true)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= aa[i]; j++) s += ab[i];
	}
	for (int i = 1, j = s.size(); i <= j; i++, j--)
	{
		if (s[i] != s[j]) ans++;
	}
	printf ("%d", ans);
	return 0;
	
}
