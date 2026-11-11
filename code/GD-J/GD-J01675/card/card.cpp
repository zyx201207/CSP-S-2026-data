#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[300005],d[500005],ans[300005],cnt;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (n >= 5000)
	{
		for (int i = 1;i <= n;i++)
		{
			ans[a[i]] = max(i,ans[i]);
		}
		for (int i = 1;i <= m;i++)
		{
			cout << ans[i] << ' ';
		}
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		cnt = 1;
		for (int j = i;j <= n;j++)
		{
			if (c[a[j]] != 0 && d[c[a[j]]] == a[j] && c[a[j]] < cnt)
			{
				cnt = c[a[j]];
				d[cnt] = a[j];
			}
			else
			{
				c[a[j]] = cnt;
				d[cnt] = a[j];
			}
			cnt++;
			/*for (int x = 1;x <= cnt;x++)
			{
				cout << d[x] << ' ';
			}
			cout << endl;*/
		}
		for (int j = 1;j < cnt;j++)
		{
			ans[d[j]]++;
		}
		//cout << endl;
	}
	for (int i = 1;i <= m;i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
