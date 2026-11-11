#include <cstdio>
#include <cstring>
using namespace std;

const int N = 5e5 + 5;
int A[N], ans[N], table[N], n, m;
bool vis[N];

int main()
{
	freopen("card.in", "r",stdin);
	freopen("card.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for (int i = 1;i <= n;i++) scanf("%d", &A[i]);
	
	for (int i = 1;i <= n;i++)
	{
		memset(table, 0, sizeof(table));
		memset(vis, 0, sizeof(vis));
		for (int j = i, k = i;k <= n;j++, k++)
		{
			if (vis[A[k]]) for (;table[j] != A[k] && j >= i;j--) vis[table[j]] = 0;
			else
			{
				table[j] = A[k];
				vis[A[k]] = 1;
			}
		}
		for (int i = 1;i <= m;i++)
			if (vis[i])
				ans[i]++;
	}
	for (int i = 1;i <= m;i++) printf("%d ", ans[i]);
	
	return 0;
}
