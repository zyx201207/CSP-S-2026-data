#include<iostream>
#include<algorithm>
using namespace std;

long long a[5000005];
long long f[5000005];
long long p[100005];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n = 0;
	long long m = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n - 1; i++)
	{
		f[i] = a[i + 1] - a[i];
	}
	int g = 2;
	while(1)
	{
		int ans = 2000000000;
		for(int i = g - 1; i <= n - 1; i++)
		{
			int k = 0;
			int o = g - 1;
			int maxx = -2000000000;
			for(int j = i - g + 2; j <= i; j++)
			{
				if(f[j] > maxx)
					maxx = f[j];
			}
			for(int j = i - g + 2; j <= i; j++)
			{
				k = k + (maxx - f[j]);
			}
			ans = min(ans, k);
		}
		if(ans >= m)
		{
			cout << g - 1 << endl;
			return 0;
		}
		g++;
	}
	return 0;
 } 
