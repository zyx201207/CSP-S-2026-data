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
	void wt(int x)
	{
		if(x > 9)
			wt(x/10);
		putchar(x%10^48);
	}
	void write(int x)
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
const int N = 5e5+10;
int n, ans;
long long m, a[N], sum[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++)
		a[i] = read();
	sort(a+1, a+n+1, [](const long long x, const long long y){
		return x < y;
	});
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i-1]+a[i];
	int l = 1, r = 1;
	while(r <= n)
	{
		long long as = a[r]*(r-l+1)-(sum[r]-sum[l-1]);
		if(as <= m)
		{
			ans = max(ans, r-l+1);
			r++;
		}
		else
			l++;
	}
	write(ans);
	return 0;
}
