#include <iostream>
using namespace std;

int a[500005];

int jl[500005][300005];

bool flag[5005][3005];

int cnt[300005];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			jl[j][a[i]] = j - i;
			flag[i][a[j]] = true;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		int minn = 2147483647;
		for(int j = 0; j < i; j++)
		{
			if(!flag[j]) minn = min(minn, i);
			else if(flag[j]) minn = min(minn, i - j);
		}
		cnt[a[i]] += minn;
	}
	for(int i = 1; i <= m; i++)
	{
		cout << cnt[i] << " ";
	}
	return 0;
}
