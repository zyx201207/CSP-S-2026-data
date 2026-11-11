#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
ll a[N];
ll sum[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	ll m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	int l = 1, ret = 1;
	/*
	稍微有点紧张，记录一下，放松一下
	考虑求排序一下，发现如果亲钦定糖果变成x，那么一定在序列上是个连续段
	这个连续段满足x*段长-sum<=m
	所以考虑双指针 
	sum1=a1
	sum2=a1+a2
	我的前缀和求完才排序的，给我人看傻了 
	*/
//	for (int i = 2; i <= n; ++i)
//	{
//		for (int j = 1; j < i; ++j)
//		{
//			ll len = i - j;
//			ll sum1 = sum[i - 1] - sum[j - 1];
//			if (len * a[i] - sum1 <= m)
//			{
//				ret = max(ret, i - j + 1);
//				break;
//			}
//		}
//	}
//	cout << ret;
	for (int i = 2; i <= n; ++i)
	{
		while (l <= i)
		{
			ll len = i - l;
			ll sum1 = sum[i - 1] - sum[l - 1];
			if (len * a[i] - sum1 > m) l++;
			else
			{
				ret = max(ret, i - l + 1);
				break;  
			}
		}
	}
	cout << ret;
}
