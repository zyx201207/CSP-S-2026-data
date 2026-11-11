#include <bits/stdc++.h>
using namespace std;

const int N = 3 * 1e5;
long long n, sum = 0, now = 0, a[N], cur1, cur2, ans = 0;
char c[N]; 

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	cur1 = 1, cur2 = n;
	while(now < sum / 2)
	{
		if(a[cur1] > a[cur2])
		{
			if(c[cur1] != c[cur2])
			{
				ans += a[cur2];
				if(now >= sum / 2)
				{
					ans -= now - (sum / 2);
					break;
				}
			}
			now += a[cur2];
			a[cur1] -= a[cur2];
			cur2 --;
		}
		else if(a[cur1] < a[cur2])
		{
			if(c[cur1] != c[cur2])
			{
				ans += a[cur1];
				if(now >= sum / 2)
				{
					ans -= now - (sum / 2);
					break;
				}
			}
			now += a[cur1];
			a[cur2] -= a[cur1];
			cur1 ++;
		}
		else 
		{
			if(c[cur1] != c[cur2])
			{
				ans += a[cur2];
				if(now >= sum / 2)
				{
					ans -= now - (sum / 2);
					break;
				}
			}
			now += a[cur2];
			cur1 ++;
			cur2 --;
		}
	}
	cout << ans << "\n";
}
