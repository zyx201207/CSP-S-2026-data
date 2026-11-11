#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int cc, tt;
int a[310];
int dis1[310], dis2[310], dis3[310];
int n, d;

void upd(int x, int val)
{
	if (val < dis3[x])
		dis3[x] = val;
	if (dis3[x] < dis2[x])
		swap(dis2[x], dis3[x]);
	if (dis2[x] < dis1[x])
		swap(dis1[x], dis2[x]); 
}

void dfs(int x, int ln)
{
	upd(x, ln);
	for (int i = x + 1; i <= n && a[i] - a[x] <= d; ++i)
		dfs(i, ln + 1);
}

void work()
{
	cin >> n >> d;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		memset(dis1, 0x3f, sizeof dis1);
		memset(dis2, 0x3f, sizeof dis2);
		memset(dis3, 0x3f, sizeof dis3);
		dfs(i, 0);
		for (int j = i + 1; j <= n; ++j)
			cnt += (dis1[j] == dis2[j] && dis2[j] != dis3[j]);
	}
	cout << cnt << '\n';

}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> cc >> tt;
	while (tt--)
		work();
	return 0;
}