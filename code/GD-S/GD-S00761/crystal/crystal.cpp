#include <bits/stdc++.h>
using namespace std;
long long a[500001];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	scanf("%lld", &n);
	scanf("%lld", &m);
	for(int i = 1; i<=n; i++)
	{
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	int l = 1, ans = 0;
	long long sum = 0;
	for(int i = 1; i<=n; i++)
	{
		sum+=a[i];
		while(a[i]*(i-l+1)-sum>m)
		{
			sum-=a[l];
			l++;
		}
		ans=max(ans, i-l+1);
	}
	cout << ans;
	return 0;
}
