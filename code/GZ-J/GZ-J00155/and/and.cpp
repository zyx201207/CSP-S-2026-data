//¿ÓºŒ¡˙ GZ-J00155
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m, a[200000], o;
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	o = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			if ((a[i] & a[j]) > o) o = a[i] & a[j];
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int x = 0; x < n; x++)
			{
				if ((o & a[j]) > o) o = (o & a[j]);
			}
		}
	}
	cout << o;
	return 0;
 } 
