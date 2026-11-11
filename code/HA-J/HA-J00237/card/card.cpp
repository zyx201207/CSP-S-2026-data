#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (a[i]==j) ans[j]++;
		}
	}
	for (int i=1;i<=j;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}

