#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n;
int a[N];
char c[N];

signed main () 
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%lld", &a[i]);
		char cc = getchar();
		while (!(cc >= 'a' && cc <= 'z')) cc = getchar();
		c[i] = cc;
	}
	
	int l, r;
	l = 1, r = n;
	
	int ll, rr;
	ll = 1, rr = 1;
	
	long long ans = 0;
	
	while (true) 
	{
		if (l == r) break;
		int tmp1 = (a[l] - ll + 1), tmp2 = (a[r] - rr + 1);
		if (c[l] == c[r]) 
		{
			int sum = min(tmp1, tmp2);
			ll += sum, rr += sum;
			if (ll > a[l]) ll = 1, l ++;
			if (rr > a[r]) rr = 1, r --;
			if (l >= r) break;
		}
		else
		{
			int sum = min(tmp1, tmp2);
			ans += sum;
			ll += sum, rr += sum;
			if (ll > a[l]) ll = 1, l ++;
			if (rr > a[r]) rr = 1, r --;
			if (l >= r) break;
		}
	}
	
	printf("%lld\n", ans);
	//1000000000
	return 0;
}
