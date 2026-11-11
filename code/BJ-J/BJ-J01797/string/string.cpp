/*
 小 R 有一个长度为 L 的字符串 S = s 1 . . . s L ,其中只包含小写英文字母。小 R 发
现,虽然 S 可能很长,但它可以分成 n 个连续的段,其中第 i (1 ≤ i ≤ n) 段由 a i 个小
∑
写英文字母 c i 构成。把这 n 段依次拼接起来便得到 S,因此 L = ni=1 a i 。相邻两段中
的字符可以相同。
小 X 喜欢回文串。若一个字符串反转后与原字符串相同,就称它是回文串,例如
aba、abba 都是回文串,而 aabbc 不是。也就是说,字符串 S 是回文串,当且仅当对
于所有 i (1 ≤ i ≤ L),均有 s i = s L+1−i 。
小 X 想让小 R 把 S 改成回文串。小 R 可以将 S 中任意一个位置的字符修改成任
意小写英文字母。他想用尽量少的修改满足小 X 的要求。
你需要帮助小 R 求出,他最少需要修改多少个位置的字符,才能将 S 改成回文串。
  */
#include "bits/stdc++.h"
#define int long long
using namespace std;
struct X
{
	int l, r, len;
	char c;
}a[200005];
int n, now, cnt, ans;
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int len;char c;
		cin >> len >> c;
		now++;
		//cout << now << '\n';
		int r = now + len - 1;
		a[++cnt] = {now, r, len, c};
		now += len - 1;
	}
	int l = 1, r = now, il = 1, ir = cnt;
	while(l < r)
	{
		int mnlen = min(a[il].len, a[ir].len);
		ans += mnlen * (a[il].c != a[ir].c);
		l += mnlen, r -= mnlen;
		a[il].len -= mnlen, a[ir].len -= mnlen;
		if(l > a[il].r)
		{
			il++;
		}
		if(r < a[ir].l)
		{
			ir--;
		}
	}
	cout << ans;
	//cout << "Hello, World!";
	return 0;
}
