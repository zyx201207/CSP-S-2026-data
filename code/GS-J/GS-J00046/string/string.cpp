#include<bits/stdc++.h>
using namespace std;

long long x, n, ans, q;
string y; 
char z;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> z;
		for (int j = 1; j <= x; j++)
		{
			y += z;
		}
		q += x; 
	}
	for (int i = 0; i < q / 2; i++)
	{
		if (y[i] != y[q - i - 1]) ans++;
	}
	cout << ans;
	return 0;
}
