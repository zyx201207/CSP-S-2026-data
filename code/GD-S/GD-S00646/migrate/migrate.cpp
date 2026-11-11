#include <bits/stdc++.h>
using namespace std;
namespace FastIO{
	const int NN = 1<<17;
	char buf[NN], *p1, *p2;
	#define gt() (p1 == p2 && (p2 = (p1 = buf)+fread(buf, 1, NN, stdin), p1 == p2)? EOF:*p1++)
	long long read()
	{
		long long x = 0, f = 1;
		char c = gt();
		while(c < '0' || c > '9')
		{
			if(c == '-')
				f = -1;
			c = gt();
		}
		while('0' <= c && c <= '9')
			x = x*10+(c^48), c = gt();
		return x*f;
	}
	void wt(long long x)
	{
		if(x > 9)
			wt(x/10);
		putchar(x%10^48);
	}
	void write(long long x)
	{
		if(x < 0)
		{
			putchar('-');
			x = -x;
		}
		wt(x);
	}
}
using FastIO::read;
using FastIO::write;
const int N = 2e6+10;
int t, n, f[N], g[N], r[N], que[N], front, back;
long long x[N], d;
int solve(int s)
{
	int as = 0;
	f[s] = 0;
	g[s] = 1;
	front = 1, back = 1;
	que[1] = s;
	for(int i = s+1, l = s; i <= n; i++)
	{
		while(x[i]-x[l] > d)
			l++;
		if(l == i)
			return as;
		f[i] = f[l]+1;
		if(l+2 < i && f[l] == f[l+1] && f[l] == f[l+2])
			g[i] = g[l]+g[l+1]+g[l+2];
		else if(l+1 < i && f[l] == f[l+1])
			g[i] = g[l]+g[l+1];
		else
			g[i] = g[l];
		if(g[i] > 3)
			g[i] = 3; 
		if(g[i] == 2)
			as++;
		while(front <= back && que[front] < l)
			front++;
		if(front > back)
			return as;
		if(g[i] <= 2)
			que[++back] = i;
	}
	return as;
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	read();
	t = read();
	while(t--)
	{
		n = read(), d = read();
		for(int i = 1; i <= n; i++)
			x[i] = read();
		for(int i = n, rr = n; i > 0; i--)
		{
			while(x[rr]-x[i] > d)
				rr--;
			r[i] = rr;
		}
		memset(f, 0, sizeof(f[0])*(n+1));
		memset(g, 0, sizeof(g[0])*(n+1));
		long long ans = 0, as = 0;
		for(int i = 1; i <= n; i++)
		{
			if(r[i] > r[i-1])
				ans += (as = solve(i));
			else
				ans += as;
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
