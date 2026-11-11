#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxm = -1;
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		if (a[i] > maxm)
		{
			maxm = a[i];
		}
	}
	if (m == 1)
	{
		cout << maxm;
		return 0;
	}
	if (m == n)
	{
		long long answer = a[1];
		for (int i = 2 ; i <= m ; i++)
		{
			answer &= a[i];
		}
		cout << answer;
		return 0;
	}
	sort(a + 1,a + n + 1);
	long long answer = a[n];
	for (int i = n - 1 ; i > n - m ; i--)
	{
		answer &= a[i];
	}
	cout << answer;
	return 0;
}
