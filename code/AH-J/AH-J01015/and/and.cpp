#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n, a[MAXN], m, w[MAXN][35], sum;
bool vis[MAXN];
void ch(int i, int x)
{
	int tot = 0;
	while (x)
	{
		w[i][++tot] = x % 2;
		x /= 2;
	}
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ch(i, a[i]);
	}
	for (int i = 31; i; i--)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (vis[j]) continue;
			if (w[j][i]) cnt++;
		}
		if (cnt >= m)
		{
			sum += (1 << (i - 1));
			for (int j = 1; j <= n; j++)
			{
				if (vis[j]) continue;
				if (!w[j][i]) vis[j] = 1;
			}
		}
	}
	cout << sum;
	return 0;
}
