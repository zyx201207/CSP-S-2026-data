#include <bits/stdc++.h>
using namespace std;

long long n,m,maxn,p; 
int ma[2000005];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	if (m == 1)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> ma[i];
	} 
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = i + 1; j <= n; j++) 
		{
			p = (ma[i] & ma[j]);
			maxn = max(p,maxn);
		}
	}
	cout << maxn;
	return 0;
} 
