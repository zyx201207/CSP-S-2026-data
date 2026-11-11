#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500005], lst[300005], ans[300005];

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		lst[a[i]] = i;
	}
	int now = 0;
	for (int i = 1;i <= n;i++)
	{
		ans[a[i]] += now + 1;
		if (i == lst[a[i]]) now = ans[a[i]];
		else now = 0;
	}
	for (int i = 1;i <= m;i++) cout << ans[i] << " ";
	return 0;
}
