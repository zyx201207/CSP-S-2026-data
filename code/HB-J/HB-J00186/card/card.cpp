#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[100005];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		vector <long long> card;
		for (int j = i; j <= n; j++)
		{
			card.push_back(a[j]);
		}
	}
	return 0;
}
