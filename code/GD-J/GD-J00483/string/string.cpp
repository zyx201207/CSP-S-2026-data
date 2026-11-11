#include <bits/stdc++.h>
using namespace std;

struct p
{
	long long x;
	char c;
};

p a[(long long)2e5 + 5];

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	for(long long i = 1;i <= n;i++)
	{
		scanf("%d %c ",&a[i].x,&a[i].c);
	}
	long long l = 1;
	long long r = n;
	long long ans = 0;
	long long lcnt;
	long long rcnt;
	long long cnt;
	lcnt = a[l].x;
	rcnt = a[r].x;
	while (l < r)
	{
		cnt = min(lcnt,rcnt);
		if (a[l].c != a[r].c)
		{
			ans += cnt;
			lcnt -= cnt;
			rcnt -= cnt;
		}
		else
		{
			lcnt -= cnt;
			rcnt -= cnt;
		}
		if (lcnt <= 0)
		{
			l++;
			lcnt = a[l].x;
		}
		if (rcnt <= 0)
		{
			r--;
			rcnt = a[r].x;
		}
	}
	cout << ans << endl;
	return 0;
} 
