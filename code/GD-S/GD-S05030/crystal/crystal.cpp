#include<bits/stdc++.h>
long long a[500005] = {0LL};
int main()
{
	std::freopen(&"crystal.in"[0],&"r"[0],stdin);
	std::freopen(&"crystal.out"[0],&"w"[0],stdout);
	long long m = 0LL,n = 0LL;
	std::scanf(&"%lld %lld"[0],&n,&m);
	for(int i = 1;(long long)(i) <= n;i = i + 1)
	{
		std::scanf(&"%lld"[0],&a[i]);
	}
	long long sum = 0LL;
	std::sort<long long *> (&a[1],&a[n + 1]);
	long long index = 0LL;
	for(int i = 2;(long long)(i) <= n;i = i + 1)
	{
		sum = sum + (long long)(i - 1) * (a[i] - a[i - 1]);
		if(sum > m)
		{
			index = (long long)(i - 1);
			break;
		}
	}
	std::printf(&"%lld"[0],index);
	return 0;
}