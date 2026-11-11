#include <iostream>
using namespace std;
typedef long long ll;
struct S{
	int a;
	char c;
} a[(int)(2e5 + 1)];
int main(){
	/*
	len1: 左边处理到第几个字符串
	len2: 右边处理到第几个字符串
	cnt1: 左边处理到字符串的哪一位
	cnt2: 右边处理到字符串的哪一位
	cnt: 已处理的字符数量 
	now: 本轮处理数 
	根据 cnt1 和 cnt2 更新 len1 和 len2
	now = 左、右字符串中剩余字符、还需处理的字符数量 中较小的那一个
	判断两个字符串字符是否相同，不同则加上本轮处理的字符数量
	cnt1 和 cnt2 和 cnt 更新
	循环条件为 剩余字符数 
	*/
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	ll cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i].a >> a[i].c;
		cnt += a[i].a;
	}
	int len1 = 0, len2 = (n + 1);
	ll cnt1 = 0, cnt2 = 0, now, ans = 0;
	cnt >>= 1;
	while (cnt){
		if (cnt1 == 0)
			cnt1 = a[++len1].a;
		if (cnt2 == 0)
			cnt2 = a[--len2].a;
		now = min(min(cnt1, cnt2), cnt);
		if (a[len1].c != a[len2].c)
			ans += now;
		cnt1 -= now;
		cnt2 -= now;
		cnt -= now;
	}
	cout << ans;
}
