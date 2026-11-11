//GZ-J00103 张万嘉 贵阳市第十九中学
#include <bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
long long n;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
	}
	long long left = 1, right = n, ans = 0, left_cnt = 0, right_cnt = 0;
	while(left <= right)
	{
		if(left_cnt > 0)
		{
			if(c[left - 1] != c[right])
			{
				ans += left_cnt;
			}
			left_cnt = 0;
			c[right] -= left_cnt;
		}
		if(right_cnt > 0)
		{
			if(c[right - 1] != c[left])
			{
				ans += right_cnt;
			}
			right_cnt = 0;
			c[left] -= right_cnt;
		}
		if(c[left] != c[right]) ans += min(a[left], a[right]);
		if(a[left] > a[right]) left_cnt = a[left] - a[right];
		else if(a[right] > a[left]) right_cnt =  a[right] - a[left];
		left++;
		right--;
	}
	cout << ans;
	return 0;
}
