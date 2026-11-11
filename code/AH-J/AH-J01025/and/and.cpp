#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N];
int n, m;

int dfs(int index, int m, int ans)
{
	if (!m) return ans;
	if (index > n) return 0;
	return max(dfs(index + 1, m - 1, ans & a[index]), dfs(index + 1, m, ans));
}


signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	
	printf("%d\n", dfs(1, m, INT_MAX));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

