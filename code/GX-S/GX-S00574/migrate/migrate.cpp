#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+5;
int n,x[N],d;
inline int read()
{
	int k = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = k * 10 + c - '0';
		c = getchar();
	}
	return k*f;
}
inline void write(int x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x < 10)
	{
		putchar(x + '0');
	}
	else
	{
		write(x / 10);
		putchar(x % 10 + '0');
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int c,t;
	c = read(),t = read();
	c = c + 1;
	while(t--)
	{
		n = read(),d = read();
		for (int i = 1;i <= n;i++)
		{
			x[i] = read();
		}
		int cha = x[2] - x[1];
		int ans = 0,i = 3;
		int caa = cha * 3;
		while (d >= caa)
		{
			i+=2;
			caa += cha;
		}
		if (d >= cha * 2)
		{
			ans = n - i;
		}
		if (ans < 0)
			putchar('0');
		else
			write(ans);
		putchar('\n');
	}
	return 0;
}
