#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], ans[300005];
bool b[300005];
stack<int> t;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
    	cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (b[a[j]])
			{
				while (t.top() != a[j])
				{
					t.pop();
				}
			}
			else
			{
				t.push(a[j]);
				b[a[j]] = true;
			}
		}
		while (!t.empty())
		{
			ans[t.top()]++;
			t.pop();
		}
		memset(b, 0, sizeof(b));
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
    return 0;
}
