#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e6 + 1;

int n, a[MAXN], ans;
char c[MAXN];

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	for(int i = 1, j = n; i <= j; ) {
		if(c[i] != c[j]) {
			ans += min(a[i], a[j]);
		}
		int tmp = min(a[i], a[j]);
		a[i] -= tmp, i += !a[i];
		a[j] -= tmp, j -= !a[j];
	}
	cout << ans;
	return 0;
}
//糖果罐里好多颜色
//微笑却不甜了 
//[忘了]
//在没有我的时刻
//中古世纪的城市里
//我想就走到这
//海鸥不在眷恋大海
//可以飞更远
//远方传来风笛
//我却在意有你的消息
//[忘了]秘密
//而我为你守着回忆 
