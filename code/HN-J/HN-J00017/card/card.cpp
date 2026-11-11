#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n, m;
int a[N];
int ans[M];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		stack<int> st;
		int cnt[M] = {0};
		for (int j = i; j <= n; j++)
		{
			if (cnt[a[j]])
				while (!st.empty())
				{
					if (st.top() == a[j]) break;
					ans[st.top()]--;
					cnt[st.top()] = 0;
					st.pop();
				}
			else
			{
				st.push(a[j]);
				ans[a[j]]++;
				cnt[a[j]] = 1;
			}
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
