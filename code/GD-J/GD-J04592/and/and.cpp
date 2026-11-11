#include<bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 5;
int n, m, ans, a[maxn], b[maxn][35];
vector<int> st, tmp;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
	{
		cin >> a[i];
		st.push_back(i);
	}
	for (int i = 1; i <= n; ++ i)
	{
		int x = a[i], j = 0;
		while (x != 0)
		{
			b[i][j] = x % 2;
			x /= 2;
			++ j;
		}
	}
	for (int i = 31; i >= 0; -- i)
	{
		int cnt = 0;
		tmp.clear();
		for (auto v : st)
		{
			if (b[v][i] == 1)
			{
				++ cnt;
				tmp.push_back(v);
			}
		}
		if (cnt >= m)
		{
			ans += (1 << i);
			st.clear();
			for (auto v : tmp)
			{
				st.push_back(v);
			}
		}
	}
	cout << ans;
	return 0;
}

