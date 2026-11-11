#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n, m;
int cnt[40];
int b[N];
int a[N];

signed main () 
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%lld", &a[i]);
		b[i] = a[i];
		for (int j = 1; j <= 32; j++) 
		{
			if (a[i] & (1ll << j - 1)) cnt[j] ++;
		}
	}
	
	int tmp = 0;
	
	int ans = 0;
	
	int siz = n;
	
	for (int i = 32; i >= 1; i --) 
	{
		int x = 0;
		if (cnt[i] >= m) 
		{
			ans = ans + (1ll << i - 1);
			for (int j = 1; j <= siz; j++) 
			{
				if (b[j] & (1ll << i - 1)) b[++ x] = b[j];
			}
			for (int j = 1; j <= 32; j++) cnt[j] = 0;
			siz = x;
			for (int j = 1; j <= siz; j++) 
			{
				for (int k = 1; k <= 32; k++) if (b[j] & (1ll << k - 1)) cnt[k] ++;
			}
		}
	}
	
	printf("%lld", ans);
	
	return 0;
}
