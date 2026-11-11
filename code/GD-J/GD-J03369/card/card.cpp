#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i]; 
	}
	
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		cout << 0 << " ";
	}
	return 0;
}
