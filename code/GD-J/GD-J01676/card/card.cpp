#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n,m,a[maxn],t[300005];
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i < n;i++)
	{
		vector<int> v;
		for (int j = i;j <= n;j++)
		{
			v.push_back(a[j]);
			bool num = -1;
			for (int k = 0;k < v.size() - 1;k++)
			{
				if (v[k] == a[j])
				{
					num = k;
					break;
				}
			}
			if (num != -1)
			{
				for (int k = num;k < v.size() - 1;k++)
				{
					v.erase(v.begin() + k);
				}
			}
		}
		for (int j = 0;j < v.size();j++)
		{
			t[v[j]]++;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << t[i] << " ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
