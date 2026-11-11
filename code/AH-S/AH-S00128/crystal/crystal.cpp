#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;
const int N = 5e5 + 10;
ll arr[N], dp[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr + 1, arr + n + 1);
	for (ll i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + arr[i];
	}
	ll maxn = INT_MIN;
	for (ll i = 1; i <= n; i++) {
		ll l = 1, r = i - 1, mid;
		while (l < r) {
			mid = l + (r - l) / 2;
			if (arr[i] * (i - l) - (dp[i - 1] - dp[mid - 1]) <= m) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		maxn = max(maxn, i - l + 1);
	}
	printf("%lld", maxn);
	
	return 0;
}

/*
Is there anyone who want to get Q1?

能量水晶(crystal)
【题目描述】
小 R 有 n 颗能量水晶,其中第 i (1 ≤ i ≤ n) 颗的能量值为整数 ai 。
小 R 想用其中若干颗能量水晶合成一颗大水晶,用于合成的水晶必须具有相同的
能量值。小 R 希望参与合成的水晶尽可能多。他可以进行至多m 次操作。每次操作可
以任选一颗水晶,将其能量值增加 1;同一颗水晶可以被重复选择。
你需要帮助小 R 求出,进行至多 m 次操作后,他最多能用多少颗能量水晶合成一
颗大水晶。
【输入格式】
从文件 crystal.in 中读入数据。
输入的第一行包含一个正整数 n 和一个非负整数 m,分别表示能量水晶的数量和
最多可以进行的操作次数。
输入的第二行包含 n 个整数 a1 , a2 , . . . , an ,依次表示每颗能量水晶的能量值。
【输出格式】
输出到文件 crystal.out 中。
输出一行一个正整数,表示进行至多 m 次操作后,小 R 最多能用多少颗能量水晶
合成一颗大水晶。
【样例 1 输入】
5 5
1 2 4 8 9
【样例 1 输出】
3
【样例 1 解释】
小 R 有 5 颗能量水晶,能量值分别为 1, 2, 4, 8, 9。他可以对能量值为 1 和 2 的水晶
分别操作 3 次和 2 次,使原来能量值为 1, 2, 4 的三颗水晶的能量值都变成 4,共进行 5
次操作。因此小 R 可以用 3 颗能量水晶合成一颗大水晶。
对于所有测试数据,均有:
1 ≤ n ≤ 5 × 10^5 ,0 ≤ m ≤ 10^18 ;
对于所有 i (1 ≤ i ≤ n),均有 |ai| ≤ 10^12 。 
*/
