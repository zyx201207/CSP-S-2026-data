#include <bits/stdc++.h>

using namespace std;

long long n,m,a[200010],s = -9999999,q[200010];

long long js ()
{
	long long sss = q[1];
	for (int h = 2;h <= m;h++) sss = sss & q[h];
	return sss;
}
void dfs (long long aa,long long bb)
{
	q[bb] = a[aa];
	if (bb == m)
	{
		s = max (s,js ());
		return;
	}
	for (int i = aa + 1;i <= n;i++) dfs (i,bb + 1);
	return;
}

int main ()
{
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	
	scanf ("%lld %lld",&n,&m);
	for (int i = 1;i <= n;i++) scanf ("%lld",&a[i]);
	for (int i = 1;i <= n - m + 1;i++) dfs (i,1);
	/*q[0] = a[1];
	q[1] = a[1];
	for (int i = 2;i <= n;i++)
	{
		q[i] = q[i - 1] & a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		for (int h = i;h <= n;h++)
		{
			s = max (q[i] & q[h],s);
		}
	}*/
	printf ("%lld",s);
	return 0;
}
