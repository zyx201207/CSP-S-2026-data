#include <bits/stdc++.h>

using namespace std;

long long c,t,mi = -999;

void dfs (long long tiao,long long wei,long long sd)
{
	if (tiao > wei) return;
	else if (tiao == wei) 
	{
		if (sd - 1
		return;
	}
	for (int i = tiao + 1;i <= wei;i++) dfs (i,wei,sd + 1);
	return;
}

int main ()
{
	//freopen ("migrate.in","r",stdin);
	//freopen ("migrate.out","w",stdout);
	
	scanf ("%lld %lld",&c,&t);
	for (int i = 1;i <= t;i++)
	{
		long long n,d,x[2000010];
		scanf ("%lld %lld",&n,&d);
		for (int h = 1;h <= n;h++) scanf ("%lld",&x[h]);
		for (int h = 1;h <= n;h++)
		{
			for (int f = h;f <= n;f++)
			{
				for (int g = h + 1;g <= f;g++) dfs (g,f,1);
			}
		} 
	}
	return 0;
}
