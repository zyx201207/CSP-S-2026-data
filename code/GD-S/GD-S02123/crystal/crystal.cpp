#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
int n;
long long m, a[N];
long long cst, ans, len;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++) 
		scanf("%lld", a+i);
	a[0] = a[1];
	sort(a+1, a+n+1);
	int j = 1;
	for(int i = 1; i <= n; i++)
	{
		cst += (a[i] - a[i-1]) * len;
		len++;
		while(cst > m)
		{
			cst -= a[i] - a[j];
			j++;
			len--;
		}
		ans = max(ans, len);
	}
	cout << ans;
	return 0;
} 
