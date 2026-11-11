#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
vector<int> v[300005];
bool flag[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		v[a[i]].push_back(i);
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = i + 1;j <= n;j++)
			flag[j] = false;
		for (int j = i + 1;j <= n;j++)
		{
			for (int k : v[a[j]])
			{
				if (k == j)
					break;
				if (k > i && flag[k])
					for (int d = k;d < j;d++)
						flag[d] = false;
			}
			flag[j] = true;
		}
//		for (int j = i + 1;j <= n;j++)
//			cout << flag[j] << " ";
//		cout << endl;
		for (int j = i + 1;j <= n;j++)
			if (flag[j])
				ans[a[j]]++;
	}
	for (int i = 1;i <= m;i++)
		cout << ans[i] << " ";
	return 0;
}
/*
4 3
1 2 1 3
*/
