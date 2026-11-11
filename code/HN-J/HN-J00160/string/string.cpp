#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll ans;
ll a[200009];
char c[200009];
ll len;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for(ll i=0; i<n; i++)
	{
		scanf("%lld %c", &a[i], &c[i]);
		len += a[i];
	}
	for(ll i=0, j=n-1; j>i&&i<j; )
	{
		if (c[i] != c[j])
		{
			if (a[i] > a[j])
			{
				ans += a[i] - a[j];
				a[i] -= a[j];
				a[j] = 0;
				j--;
			}
			else if (a[i] < a[j])
			{
				ans += a[j] - a[i];
				a[j] -= a[i];
				a[i] = 0;
				i++;
			}
			else
			{
				ans += a[i];
				a[i] = a[j] = 0;
				i++, j--; 
			}
		}
		else
		{
			if (a[i] > a[j])
			{
				a[i] -= a[j];
				a[j] = 0;
				j--;
			}
			else if (a[i] < a[j])
			{
				a[j] -= a[i];
				a[i] = 0;
				i++;
			}
			else
			{
				a[i] = a[j] = 0;
				i++, j--; 
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
