#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gc getchar()
#define cs const
#define pf printf
#define fr(x) freopen(x, "r", stdin)
#define fw(x) freopen(x, "w", stdout)
inline ll read()
{
	ll sum = 0, f = 1;
	char ch = gc;
	while (ch > '9' || ch < '0')	
	{
		if (ch == '-')
			f = -1;
		ch = gc;
	}
	while (ch >= '0' && ch <= '9')
	{
		sum = 10 * sum + ch - '0';
		ch = gc;
	}
	return sum * f;
} 
#define rd read()

ll cs N = 5e5 + 5;
ll m, n, a[N]; 
ll sum, ans = 1;
ll ld, sz;

signed main()
{
	fr("crystal.in");
	fw("crystal.out");
	n = rd, m = rd;
	for (int i = 1; i <= n; i++)
		a[i] = rd;
	sort(a + 1, a + 1 + n);
	sum = 0, ans = 1;
	ld = 1, sz = 1;
	for (int i = 2; i <= n; i++)
	{
		sum += sz * (a[i] - a[i - 1]);
		if (sum > m)
			while (sum > m)
			{
				sum -= (a[i] - a[ld++]);
				sz--;
			}
		ans = max(ans, sz + 1);
		//算上自己 
		sz++;
//		pf("%lld\n", sz);
	}
	pf("%lld", ans);
	return 0;
}
/*
题目即进行m次 + 1的操作
求最多有几个数相同
设i为相同的数字 排序后数组为A 
则最少的贡献一定是从i往前若干位需要的总和
可建一个队列q 和 当前总和 sum 
从第一个数开始将下标入队 
q push i
往下枚举时sum 增加 q.size * (Ai - Ai-1)
若此时队首超出
则弹出并减小对应贡献 


14:48 AC
*/
