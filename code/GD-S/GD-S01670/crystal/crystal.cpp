#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read();
const int N = 5e5 + 10;
ll a[N], b[N], st[N][70], rem[N];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		b[i] = b[i - 1] + a[i];
		st[i][0] = a[i];
	}
	bool f1 = 1;
	ll last = a[2] - a[1];
	for(int i = 2; i <= n; i++)
	{
		if(a[i] - a[i - 1] != last)
		{
			f1 = 0;
			break;
		}
	}
	if(f1)
	{
		//if(last < 0) reverse(a + 1, a + n + 1);
		last = abs(last);
		int l = 0, r = n;
		while(l < r)
		{
			int mid = (l + r + 1) >> 1;
			ll sum = 1ll * mid * (mid - 1) / 2 * last;
			if(sum <= m) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", l);
		return 0;
	}
	rem[n] = a[n];
	for(int i = n - 1; i >= 1; i--) rem[i] = max(a[i], rem[i + 1]);
	int len = log2(n);
	for(int j = 1; j <= len; j++)
	{
		for(int i = 1; i <= n; i++)
		{
			if(i + (1 << j) - 1 <= n) st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
			else st[i][j] = rem[i];
		}
	}
	/*for(int j = 1; j <= len; j++)
	{
		for(int i = 1; i <= n; i++)
		{
			printf("%d %d %d\n", i, j, st[i][j]);
		}
	}
	return 0;*/
	ll ans = 1;
	for(int l = 1; l <= n; l++)
	{
		for(int r = l + ans; r <= n; r++)
		{
			int t = log2(r - l + 1);
			ll maxn = max(st[l][t], st[r - (1 << t) + 1][t]);
			ll all = (r - l + 1) * maxn - (b[r] - b[l - 1]);
			//if(l <= 2) printf("%d %d %d\n", l, r, all);
			if(all <= m) ans = max(ans, (ll)r - l + 1);
			else break;
		}
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4
2 4 6 8
ans:2
5 5
1 2 4 8 9
ans:3
5 8
-3 -1 2 2 7
ans:4
5 5
-2 -3 -1 -5 -2
ans:3
*/
inline ll read()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
