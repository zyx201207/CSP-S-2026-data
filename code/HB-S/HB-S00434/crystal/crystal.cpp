#include <bits/stdc++.h>

using namespace std;

long long n,m,mm,a[500010],s = -99999,ss = 1;

int main ()
{	
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	scanf ("%lld %lld",&n,&m);
	for (int i = 1;i <= n;i++)
	{
		scanf ("%lld",&a[i]);
	}
	sort (a + 1,a + n + 1);
	for (int i = n;i >= 1;i--)
	{
		mm = m;
		ss = 1;
		for (int h = i - 1;h >= 1;h--)
		{
			if (mm >= a[i] - a[h]) 
			{
				mm -= a[i] - a[h];
				ss++;
			}
			else break;
		}
		if (ss > s) s = ss;
	}
	printf ("%lld",s); 
	return 0;
}
