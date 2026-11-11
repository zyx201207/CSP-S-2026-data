#include <bits/stdc++.h>
using namespace std;
long long n,m,num[500005],cha[500005],nsum[500005],l,r;
long long read()
{
	char c = getchar();
	long long res = 0,x = 1;
	while (c < '0' || c > '9')
	{
		if (c == '-')
		{
			x = -1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * x;
}
void wr(long long x)
{
	if (x > 10)
	{
		wr(x / 10);
	}
	putchar(x % 10 + '0');
	return ;
}
void write(long long x)
{
	if (x < 0)
	{
		x = -x;
		putchar('-');
	}
	wr(x);
	return ;
}
bool check(long long x)
{
	for (int i = x;i <= n;i++)
	{
		long long res = 0;
		for (int j = i - x;j < i;j++)
		{
			res += nsum[i] - nsum[j];
		}
		if (res <= m)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
	n = read();
	m = read();
	for (int i = 1;i <= n;i++)
	{
		num[i] = read();
	}
	sort(num + 1,num + n + 1);
	for (int i = 1;i <= n;i++)
	{
		cha[i] = num[i] - num[i - 1];
		nsum[i] = cha[i] + nsum[i - 1];
	}
	l = 1;
	r = n;
	while (l < r)
	{
		long long mid = (l + r + 1) >> 1;
		if (check(mid))
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << l + 1;
 	return 0;
}

