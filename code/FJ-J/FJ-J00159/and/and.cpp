#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2e5 + 5;
int num[N], A[N], n, m, maxn = 0;
bool vis[N];

void cnt_ans()
{
	int ans = ((1 << 30) - 1) * 2 + 1;
	for (int i = 1;i <= m;i++) ans &= num[i];
	maxn = max(maxn, ans);
}

void dfs(int cnt, int j)
{
	if (cnt > m)
	{
		cnt_ans();
		return;
	}
	for (int i = j + 1;i <= n;i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			num[cnt] = A[i];
			dfs(cnt + 1, i);
			vis[i] = 0;
		}
	}
}

int main()
{
	memset(vis, 0, sizeof(vis));
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for (int i = 1;i <= n;i++) scanf("%d", &A[i]);
	dfs(1, 0);
	printf("%d", maxn);
	return 0;
}
