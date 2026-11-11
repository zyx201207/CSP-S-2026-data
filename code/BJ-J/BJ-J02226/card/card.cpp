#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int t[500005],t2[300005];
int main()
{
	freopen("card5.in","r",stdin);
	freopen("card5.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		t2[a[i]] = max(i,t2[a[i]]);
	}
	for (int i = 1;i <= n;i++)
		t[i] = t2[a[i]];
	for (int i = 1;i <= n;i++)
	{
		for (int j = i;j <= n;)
		{
			ans[a[j]]++;
			j = t[j]+1;
		}
	}
	for (int i = 1;i <= m;i++)
		cout << ans[i] << " ";
	return 0;
}