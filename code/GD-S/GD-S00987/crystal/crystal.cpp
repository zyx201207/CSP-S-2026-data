#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

using ll = long long;

const ll N = 5e5 + 5;

int n, ans;
ll m, a[N], sum[N];

void init() {}

void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + a[i];
	for (int i = 1, res; i <= n; ++i)
	{
		res = i - 1;
		for (int l = i, r = n, mid; l <= r;)
		{
			mid = (l + r) >> 1;
			// cerr << mid << ' ' << a[mid] * (mid - i + 1) - sum[mid] + sum[i - 1] << endl;
			if (a[mid] * (mid - i + 1) - sum[mid] + sum[i - 1] <= m)
			{
				res = mid;
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		// cerr << "! " << res << endl;
		ans = max(ans, res - i + 1);
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	// freopen("crystal.err", "w", stderr);
	int _ = 1;
	// cin >> _;
	init();
	while (_--)
		solve();
	return 0;
}
/*
g++ crystal.cpp -o crystal.exe -std=c++14 -O2 -Wl,-stack=2147483647
*/
/*
A 奶龙题开场 5min 秒了
n log n
好像可以不带 log 用双指针做来着，但是不想写了
B 更是奶蛙题
mad 一开始 n, m 看错然后糊了一个神秘的双指针连边然后 floyd 状物
然后发现原题更简单，都不用双指针了，直接暴力连边就是对的
(m + q)d^2 + n^3
到此为止只过了 1h
然后因为 200pts 能稳进 noip 于是决定进行一个雨男孩的倒开
推了半天只整了一个巨难写的 n^3
此时 16:20
然后转战 C，秒了一个 n^2，结果调到 17:30，没有心情想正解了
还是不会 D，不想写这个 n^3
于是转为在注释中塞入大量神秘内容
*/