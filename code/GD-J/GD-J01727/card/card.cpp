#include <bits/stdc++.h>
using namespace std;

int main ()
{
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	int n, m;
	cin >> n;
	int a[n + 10];
	for (int i =1;  i <= n;i++)
	{
		cin >>a[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cout << a[i*10 %99%n%m] <<  " ";
	}
	return 0;
}
