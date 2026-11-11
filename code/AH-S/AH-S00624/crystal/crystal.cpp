#include<bits/stdc++.h>
using namespace std;

const int N = 500005;

long long mm, m, n, a[N], t[N], sum;

void in(long long &x)
{
	long long s = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		s = s * 10 + (c - '0');
		c = getchar();
	}
	x = s * f;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	in(n); in(m);
	bool b = 1;
	long long d = 0;
	for (int i = 1; i <= n; i ++) 
	{
		in(a[i]);
		if (i == 2) d = a[i] - a[i - 1];
		if (b && i >= 2 && a[i] - a[i - 1] != d) b = 0; 
	}
	long long ans = 0;
	if (b == 1)
	{
		if (d == 0) printf("%lld\n", n);
		else if (d > 0) 
		{
			long long num = m / d;
			long long x = sqrt(2 * m);
			while (x * (x + 1) * d / 2 > m) x --;
			if (x + 1 <= n) printf("%lld\n", x + 1);
			else printf("%lld\n", n);
		}
		else 
		{
			d = -d;
			long long num = m / d;
			long long x = sqrt(2 * m);
			while (x * (x + 1) * d / 2 > m) x --;
			if (x + 1 <= n) printf("%lld\n", x + 1);
			else printf("%lld\n", n);
		}
	}
	sort(a + 1, a + 1 + n);
	for (int i = n; i >= 1; i --)
	{
		sum = 1; mm = m;
		for (int j = i - 1; j >= 1; j --)
		{
			if (mm >= a[i] - a[j])
			{
				mm -= (a[i] - a[j]);
				sum ++;
			}
			else break;
			ans = max(ans, sum);
		}
		if (ans >= i) break;
	}
//	for (int i = 1; i <= n; i ++) {
//		t[i] = t[i - 1] + (i - 1) * (a[i] - a[i - 1]);
//	}
//	long long i = 1, j = n;
//	while (i <= j)  
//	{
//		cout << i << ' ' << j << endl;
//		if (t[j] - t[i] - (i - 1) * (a[j] - a[i]) <= m) 
//		{
//			printf("%lld\n", j - i + 1);
//			return 0;
//		}
//		if (a[j] - a[i] >= (j - 1) * (a[j] - a[j - 1])) i ++;
//		else j --;
//	}
	printf("%lld\n", ans);
	return 0;
}
