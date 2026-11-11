#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

int n, a[N];
long long pll, plr, prl, prr, nl, nr, ans;
//pll是左端点的a[i]的i
//plr:枚举到左端点的a[i]的第几位
//prl是右端点的a[i]的i
//prr:枚举到右端点的a[i]的第几位
//nl表示左端点枚举到总的第几位了
//nr表示右端点枚举到总的第几位了 
char c[N];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> c[i];
		nr += a[i];
	}
	//初始化init()
	nl = plr = pll = 1;
	prl = n;
	prr = a[n];
	while (nl < nr) //只要nl没过半
	{
		ans += (c[pll] != c[prl]);//不一样就要改其中一个
		//每次的变化
		++nl;
		--nr;
		++plr;
		--prr;
		//会不会超过当前a[pll]的值
		if (plr > a[pll])
		{
			++pll;
			plr = 1;
		}
		//会不会低于0
		if (prr < 0)
		{
			--prl;
			prr = a[prl];
		}
	}
	cout << ans;
	return 0;
}
