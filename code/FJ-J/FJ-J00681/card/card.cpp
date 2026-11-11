#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[500005];
int ans[500005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	int pos = 1;
	for (int i=1;i<=m;i++)
	{
		for (int j=pos;j<=n;j++)
		{
			ans[a[j]]++;
		}
		pos++;
	}
	for (int i=1;i<=m;i++) cout << ans[i] << " ";
	return 0;
}
