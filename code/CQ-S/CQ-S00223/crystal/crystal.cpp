/*
首先必然有至少一个没变

枚举这个，然后直接做是不是就可以了哦。

前缀和，二分。
*/
#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

long long wsx[500005];
long long lhc[500005];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld", wsx + i);
	}
	sort(wsx + 1, wsx + n + 1);
	int maxn = 0;
	for(int i=1;i<=n;i++)
	{
		lhc[i] = lhc[i-1] + wsx[i];
		int l = 1, r = i;
		while(l < r)
		{
			int mid = (l + r) / 2;
			if(wsx[i] * (i - mid + 1) - (lhc[i] - lhc[mid - 1]) <= m) r = mid;
			else l = mid + 1;
		}
		maxn = max(maxn, i - l + 1);
	}
	printf("%d\n", maxn);
	return 0;
}