#include <bits/stdc++.h>
using namespace std;

const int M = 3e5 + 5;

int n, m;
long long cnt[M];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout); 
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int a; cin >> a;
		cnt[a]++;
	}
	
	for (int i = 1; i <= m; i++)
		cout << cnt[i] << " ";
	
	return 0;
}