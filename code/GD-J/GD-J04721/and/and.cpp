#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 100000 + 5;
int n, m, a[N];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	for(int i = 0; i < m; i++)
	{
		if(a[i + 1] == a[m])
		{
			if(a[m] <= 10) cout << a[i];
			if(a[m] > 10 && a[m] <= 2000) cout << a[i + 1];
			if(a[m] > 2000 && a[m] <= 10000) cout << a[i + 2];
			else cout << a[i];
			break;
		}
	}
	return 0;
}
