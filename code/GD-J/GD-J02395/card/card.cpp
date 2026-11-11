#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int tong[300010], a[500010], t1[300010], b[300010];
bool pd[300010];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i(1); i <= n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	for(int i(1); i <= n; i++)
	{
		for(int j(i); j <= n; j++)
		{
			if(t1[a[j]])
			{
				for(int k(i); k <= j; k++)
					t1[a[k]] = 0;
			}
			t1[a[j]]++;
		}
		for(int j(1); j <= n; j++)
		{
			if(t1[a[j]])
				tong[a[j]]++;
			t1[a[j]] = 0;
		}
	}
	for(int i(1); i <= n; i++)
	{
		if(b[i] != b[i - 1])
			cout << tong[b[i]] << ' ';
	}
	
	return 0;
}
