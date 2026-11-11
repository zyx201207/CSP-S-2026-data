#include<iostream>
#include<cstdio>
using namespace std;
const int N = 5e5+5, M = 3e5+5;
long long a[N], val[N], ans[M], lst[M];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, m, i;
	cin >> n >> m;
	for(i = 1; i <= n; i++)
	{
		cin >> a[i];
		lst[a[i]] = i;
		val[i] = 1;
	}
	for(i = 1; i <= n ;i++)
	{
		ans[a[i]] += val[i];
		val[lst[a[i]] + 1] += val[i];
	}
	for(i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}
