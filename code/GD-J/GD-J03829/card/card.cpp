#include <bits/stdc++.h>
#define int long long
using namespace std;
int sz[500005],ans[300005];
bool pd[300005];
stack <int> s;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >>m;
	for (int i = 1;i <= n;i++)
		cin >> sz[i];
	for (int i = 1;i <= n;i++)
	{
		while (!s.empty())
			s.pop();
		for (int j = i;j <= n;j++)
		{
			if (!pd[sz[j]])
			{
				pd[sz[j]] = 1;
				s.push(sz[j]);
			}
			else
			{
				while (s.top() != sz[j])
				{
					pd[s.top()] = 0;
					s.pop();
				}
			}
		}
		for (int i = 1;i <= m;i++)
		{
			if (pd[i])
				ans[i]++;
			pd[i] = 0;
		}
	}
	for (int i = 1;i <= m;i++)
		cout << ans[i]<< ' ';
	return 0;
} 
/*

*/
