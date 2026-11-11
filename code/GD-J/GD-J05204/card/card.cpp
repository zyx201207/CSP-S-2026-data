#include <bits/stdc++.h>
using namespace std; 
int n, m;
int a[500005], card[500005];
int main()
{
	cin >> n >> m;
	int check[m];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int b = 1;
			card[b] = a[j];
			b++;
		}
	}
	return 0;
}
