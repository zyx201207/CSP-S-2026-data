#include <bits/stdc++.h>
using namespace std;

long long a[500005];
long long s[500005];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long M;
	scanf("%d%lld", &n, &M);
	//进行特判一
	if (n == 1)
	{
		printf("1");
		return 0;
	}
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	//进行特判二
	if(M == 0)
	{
		//寻找众数
		int ans = 1, maxn = 1;
		for (int i = 2; i <= n; ++ i)
		{
			if (a[i] != a[i - 1])
			{
				maxn = max(ans, maxn);
			}
			else
			{
				++ ans;
			}
		}
		printf("%d", maxn);
		return 0;
	}
	long long m;
	long long ans, maxn = 1;//maxn 用来存储 ans 的最大值
	for (int i = 2; i <= n; ++ i)
	{
		ans = 1;//最少有一颗水晶用来合成（只有一颗水晶的话直接输出 1）
		//先计算 s 数组（si[j] 存放 a[i] - a[j]）
		for (int j = 1; j < i; ++ j)
		{
			s[j] = a[i] - a[j];
		}
		//从第 (i - 1) 项开始，判断操作次数是否能够再多搞定一个水晶
		m = M;
		for (int j = i - 1; j >= 1; -- j)
		{
			//判断是否能够再多搞定一个水晶
			if (m >= s[j])
			{
				m -= s[j];
				++ ans;
			}
		}
		//如果还没有之前大，那么也就是说 ans 不可能再往上涨了，输出 + 终止程序
		if (ans <= maxn)
		{
			break;
		}
		else
		{
			maxn = ans;
		}
	}
	printf("%lld", maxn);

	return 0;
}
