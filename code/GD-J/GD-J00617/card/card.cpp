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
const int N = 5e5+10, M = 3e5+10;
int n, m, a[N], ans[M], barrel[M], val[N];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++)
	{
		a[i] = read();
		barrel[a[i]] = i;
		val[i] = 1;
	}
	for(int i = 1; i <= n; i++)
	{
		int now = a[i];
		if(i == barrel[now])
		{
			ans[now] = val[i];
			val[i+1] += val[i];
		}
		else
			val[barrel[now]] += val[i];
	}
	for(int i = 1; i <= m; i++)
		printf("%d ", ans[i]);
	return 0;
}
