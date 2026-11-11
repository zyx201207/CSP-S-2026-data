#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N(5e5 + 5), M(3e5 + 5); 
int a[N], b[N], temp[N], ans[M];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1, num; i <= n; i++)
	{
		num = i;
		memset(b, 0, sizeof(b));
		for (int j = i, t; j <= n; j++)
		{
			if (b[a[j]])
			{
				t = b[a[j]];
				for (int k = b[a[j]]; k < num; k++)
				{
					b[temp[k]] = 0;
					temp[k] = 0;
				}
				num = t; 
			}		
			b[a[j]] = num; 	
			temp[num++] = a[j];
		}
		for (int j = i; j <= num; j++)
		{
//			cout << temp[j] << ' ';
			ans[temp[j]]++;
		}
//		cout << '\n';
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
