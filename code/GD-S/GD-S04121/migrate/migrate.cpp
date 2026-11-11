#include<iostream>
#include<cstring>
using namespace std;

int a[5001][5001];

int n = 0;
int d = 0;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c = 0;
	int t = 0;
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		if(n > 5000)
			return 0;
		memset(a, 0x3f, sizeof(a));
		int x = 0;
		cin >> x;
		for(int i = 2; i <= n; i++)
		{
			int y = 0;
			cin >> y;
			a[i - 1][i] = y - x;
			a[i][i - 1] = y - x;
			x = y;
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(i == j)
				{
					continue;
				}
				for(int k = i + 1; k <= j; k++)
				{
					a[i][k] += a[k][k - 1];
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(i == j)
				{
					continue;
				}
				for(int k = 1; k <= n; k++)
				{
					int flag = 0;
					if(k == j || k == i)
					{
						continue;
					}
					for(int l = 1; l <= n; l++)
					{
						if(k == l || j == l || i == l)
						{
							continue;
						}
						if(a[i][k] + a[k][j] == a[i][l] + a[l][j])
						{
							ans++;
							flag = 1;
							break;
						}
					}
					if(flag)
						break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
