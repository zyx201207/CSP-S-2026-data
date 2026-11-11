#include <cstdio>
#include <stack>
using namespace std;
int a[500001];
int ans[300001];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i ++)
	{
		stack<int> t;
		bool cnt[300001] = {};
		for (int j = i; j <= n; j ++)
		{
			if (cnt[a[j]] == 1)
			{
				while (t.top() != a[j])
				{
					cnt[t.top()] = 0;
					t.pop();
				}
			}
			else
			{
				cnt[a[j]] = 1;
				t.push(a[j]);
			}
		}
		for (int j = 1; j <= m; j ++)
		{
			ans[j] += cnt[j];
		}
	}
	for (int i = 1; i <= m; i ++)
	{
		printf("%d ", ans[i]);
	}
}