#include <bits/stdc++.h>
using namespace std;
struct Node{
	long long x;
	char m;
};
Node a[200005];
long long ans = 0,sum = 0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].x >> a[i].m;
		sum += a[i].x;
	}
	int l = 1,li = 1;
	int r = sum,ri = n;
	while (li < ri)
	{
		if (a[li].m != a[ri].m)
		{
			if (a[li].x > a[ri].x)
			{
				r -= a[ri].x;
				l += a[ri].x;
				ans += a[ri].x;
				a[li].x -= a[ri].x;
				ri--;
			}
			else
			{
				r -= a[li].x;
				l += a[li].x;
				ans += a[li].x;
				a[ri].x -= a[li].x;
				li++;
			}
		}
		else
		{
			if (a[li].x > a[ri].x)
			{
				r -= a[ri].x;
				l += a[ri].x;
				a[li].x -= a[ri].x;
				ri--;
			}
			else
			{
				r -= a[li].x;
				l += a[li].x;
				a[ri].x -= a[li].x;
				li++;
			}
		}
	}
	cout << ans;
	return 0;
}
