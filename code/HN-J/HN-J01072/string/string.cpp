#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n,l = 1,r,ans;
struct AC
{
	int num;
	char c;
}a[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].num >> a[i].c;
	}
	r = n;
	while (l < r)
	{
		int lnum = a[l].num,rnum = a[r].num;
		if (a[l].c != a[r].c)
		{
			if (lnum > rnum)
			{
				a[l].num -= rnum;
				a[r].num = 0;
				ans += rnum;
				r--;
			}
			else if (rnum > lnum)
			{
				a[r].num -= lnum;
				a[l].num = 0;
				ans += lnum;
				l++;
			}
			else
			{
				a[l].num = 0;
				a[r].num = 0;
				ans += lnum;
				r--;
				l++;
			}
		}
		else
		{
			if (lnum > rnum)
			{
				a[l].num -= rnum;
				r--;
			}
			else if (rnum > lnum)
			{
				a[r].num -= lnum;
				l++;
			}
			else
			{
				a[l].num = 0;
				a[r].num = 0;
				l++;
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}

