#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 100;
long long n, m, ans[N], a[N];
bool visit[N];
stack<long long> st;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		while (!st.empty()) st.pop();
		memset(visit, 0, sizeof(visit));
		for (int j = i; j <= n; j++)
		{
			if (visit[a[j]])
			{
				while (st.top() != a[j])
				{
					visit[st.top()] = 0;
					st.pop();
				}
			}
			else
			{
				st.push(a[j]);
				visit[a[j]] = 1;
			}
		}
		for (int j = 1; j <= m; j++)
			if (visit[j])
				ans[j]++;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}
