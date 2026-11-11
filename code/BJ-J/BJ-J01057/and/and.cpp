#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m, a[N];

int ans;
void DFS(int i, int tot, int sum)
{
	if (tot == m)
	{
		ans = max(ans, sum);
		return;
	}
	if (i > n) return;
	
	int nsum = (sum != -1 ? sum & a[i] : a[i]);
	DFS(i + 1, tot + 1, nsum);
	DFS(i + 1, tot, sum);
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	DFS(1, 0, -1);
	
	cout << ans;
	
	return 0;
}