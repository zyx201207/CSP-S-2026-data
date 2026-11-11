#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
constexpr int N(5e5 + 10), M(3e5 + 10);
int a[N], tong[M], arv[N];
vector<int> v[N];
bool pd[N];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int n = 0, m = 0;//5000 3000
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		arv[i] = i + 1;
		v[a[i]].emplace_back(i);
	}
	for (int i = 1; i <= m; i++)
	{
		int num = v[i].size();
		for (int j = 0; j + 1 < num; j++)
			arv[v[i][j]] = v[i][j + 1];
	}
	for (int i = 1; i <= n; i++)
	{
		int j = i;
		while (j <= n)
		{
			pd[a[j]] = true;
			j = arv[j];
		}
		for (int j = 1; j <= m; j++)
		{
			tong[j] += pd[j];
			pd[j] = false;
		}
	}
	for (int i = 1; i <= m; i++)
		cout << tong[i] << ' ';
	return 0;
}
