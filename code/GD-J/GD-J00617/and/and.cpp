#include <bits/stdc++.h>
using namespace std;
namespace FastIO{
	const int NN = 1<<17;
	char buf[NN], *p1, *p2;
	#define gt() (p1 == p2 && (p2 = (p1 = buf)+fread(buf, 1, NN, stdin), p1 == p2)? EOF:*p1++)
	int read()
	{
		int x = 0;
		char c = gt();
		while(c < '0' || c > '9')
			c = gt();
		while('0' <= c && c <= '9')
			x = x*10+(c^48), c = gt();
		return x;
	}
}
using FastIO::read;
const int N = 2e5+10;
int n, m, a[N], ans;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++)
		a[i] = read();
	for(int i = 1<<29; i; i >>= 1)
	{
		int cnt = 0;
		for(int j = 1; j <= n; j++)
			if(a[j]&i)
				cnt++;
		if(cnt >= m)
		{
			cnt = 0;
			for(int j = 1; j <= n; j++)
				if(a[j]&i)
					a[++cnt] = a[j];
			n = cnt;
			ans ^= i;
		}
	}
	printf("%d", ans);
	return 0;
}
