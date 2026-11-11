#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
const int N = 5e5 + 5;
int n,ans;
long long m,a[N];
bool check(int x)
{
	long long num = 0,sum = 0,l = 1,r = x;
	for (int i = l;i <= r;i++)
		sum += a[r] - a[i];
	while (r <= n)
	{
		if (sum <= m)
			return 1;
		l ++;
		r ++;
		num = 0;
		for (int i = l;i <= r;i++)
			num += a[r] - a[i];
		sum = num;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + 1 + n);
	int l = 0,r = n,mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid))
			l = mid + 1,ans = mid;
		else
			r = mid - 1;
	}
	cout << ans;
	return 0;
}
