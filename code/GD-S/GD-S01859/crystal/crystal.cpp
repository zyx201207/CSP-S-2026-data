#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],sum[500005],maxx;
int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);//排序，便于后续处理
	a[n + 1] = a[n];
	a[0] = a[1];
	for (int i = n;i >= 1;i--)
	{
		sum[i] = sum[i + 1] + a[n] - a[i];//类似于后缀和
	}
	long long l = 1,r = 1;
	long long x = (long long)n;
	for (;l <= x;l++)//双指针
	{
		while (((sum[l] - sum[r + 1] - (r - l + 1) * (a[n] - a[r])) <= m) && r <= x)//当整体提升所需能量小于m时与maxx比较
		{
			maxx = max(maxx,r - l + 1);
			r++;
		}
	}
	cout << maxx;
	return 0;
 }
