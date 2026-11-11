#include <iostream>
using namespace std;

int a[200005];
int n, m;
int maxn = 0;

bool flag[200005];

void dfs(int step, int num)
{
	if(step == 0)
	{
		maxn = max(maxn, num);
		return ;
	}
	for(int i = 1; i <= n; i++)
	{
		if(flag[i] == 0)
		{
			flag[i] = 1;
			dfs(step - 1, num & a[i]);
			flag[i] = 0;
		}
	}
	return ;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dfs(m, 2147483647);
	cout << maxn;
	return 0;
}
