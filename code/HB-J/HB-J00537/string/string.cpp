#include <bits/stdc++.h>

using namespace std;

long long n,a[200010],s = 0,l,r;
char c[200010];

int main ()
{
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	
	scanf ("%lld",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf ("%lld %ch",&a[i],&c[i]);
	}
	l = 1;
	r = n;
	while (r != l)
	{
		if (a[l] > a[r]) 
		{
			if (c[l] != c[r]) s += a[r];
			a[l] -= a[r];
			r--;
		}
		else
		{
			if (c[l] != c[r]) s += a[l];
			a[r] -= a[l];
			l++;
		}
	}
	printf ("%lld",s);
	return 0;
}
