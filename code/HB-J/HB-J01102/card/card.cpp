#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int a[MAXN], ans[MAXN];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	int ai;
	cin >> n >> m;
	for (int mz = 1; mz <= n; mz++)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> ai;
			for (int j = 1; j <= i; j++)
				if (a[j] == ai and ai == i)
					ans[i]--;
		}
		for (int i = 1; i <= n; i++)
			if (a[i] == i)
			{
				ans[i]++;
				break;
			}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	return 0;
}
