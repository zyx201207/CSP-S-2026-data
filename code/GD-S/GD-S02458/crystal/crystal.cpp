#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N(5e5 + 5);
long long a[N];
map<long long, int> m;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int n;
	long long m, ans, temp;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
//	for (int i = 1; i <= n; i++)
//	{
//		cout << a[i] << ' ';
//	}
	for (int i = 2, last; i <= n; i++)
	{	
		if (a[i] == a[i - 1])
		{
			ans++;
			continue;
		}  
		if (m >= (a[i] - a[i - 1]))
		{
			temp = m / (a[i] - a[i - 1]);
			if (temp > (i - 1))
			{
				temp = i - 1;
				ans = i;
			}
			else
			{
				ans = max(ans, temp + 1);
			}
//			cout << temp << ' ' << i << '\n';
			m -= temp * (a[i] - a[i - 1]);
			cout << m << ' ' << ans << ' ' << a[i] - a[i - 1] << ' ' << temp << '\n';
		}
		else
		{
//			while (a[i] == a[i + 1])
//			{
//				i++;
//			}
			break;
		}
	}
	cout << ans;
	return 0;
} 
