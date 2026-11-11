#include <bits/stdc++.h>
using namespace std;

int n, a[200001];
long long ans;
char c[200001];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %c", &a[i], &c[i]);
	}
	int i = 1, k = n;
	while(i < k)
	{
		int mn = min(a[i], a[k]);
		a[i] -= mn, a[k] -= mn;
		if(c[i] != c[k])
		{
			ans += mn;
		}
		
		if(a[i] == 0)
		{
			i++;
		}
		if(a[k] == 0)
		{
			k--;
		}
	}
	printf("%lld", ans);
	return 0;
}


