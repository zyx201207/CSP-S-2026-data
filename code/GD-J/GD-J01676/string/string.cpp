#include <bits/stdc++.h>
#define int long long
using namespace std;
struct hss
{
	int num;
	char c;
};
int n,l = 1,r,ans = 0;
hss a[200005];
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	r = n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].num >> a[i].c;
	}
	while (l < r)
	{
		if (a[l].c == a[r].c)
		{
			if (a[l].num < a[r].num)
			{
				a[r].num -= a[l].num;
				a[l].num = 0;
				l++;
			}
			else
			{
				a[l].num -= a[r].num;
				a[r].num = 0;
				r--;
			}
		}
		else
		{
			if (a[l].num < a[r].num)
			{
				ans += a[l].num;
				a[r].num -= a[l].num;
				a[l].num = 0;
				l++;
			}
			else
			{
				ans += a[r].num;
				a[l].num -= a[r].num;
				a[r].num = 0;
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}
