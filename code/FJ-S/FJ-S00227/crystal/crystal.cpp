#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5e5+5;
int n, ans;
ll m, a[N], s[N];

bool check(int j, int k)
{
	return (k-j)*a[k]-s[k-1]+s[j-1] <= m;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++)
		s[i] = s[i-1]+a[i];
	for(int k = 1, j = 1; k <= n; k++)
	{
		while(j < k && !check(j, k)) j++;
		ans = max(k-j+1, ans);
	}
	printf("%d\n", ans);
	
	return 0;
}
