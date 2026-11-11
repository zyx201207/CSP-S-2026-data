#include <bits/stdc++.h> 
using namespace std;

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long a[200005] = {}, ans = 0;
	int m, n;
	cin >> m >> n;
	for(int i=1; i<=m; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+m+1);
	ans = a[m];
	for(int i=m-1; i>m-n; i--)
	{
		ans &= a[i];
	}
	cout << ans;
	return 0;
}
