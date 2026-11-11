#include<bits/stdc++.h>
using namespace std;
/*
guanzhu _Liyx_ miao
guanzhu _Liyx_ xiexiemiao

T4 is too easy?
I found the solution at 9:45.
AC at 9:56

nailong J

Start to sleep at 10:00.

I palyed "wangzhe" from 11:00 to 12:30 yesterday.
/se/se/se

It's right that don't review before the contest./qiang

It's no doubt that J is too easy.

AKAKAKAK?
Maybe.

Lumingfei is /ruo/ruo.
Hui is /qiang/qiang.
Xiami is /qiang/qiang.
Oh, we can't use "is" for Hui and Xia, we should use the word "was". /xx
Kaisa is /qiangqiang in longsan.
Kaisa is /ruoruo in lnogsi, longwu.
Nuonuo is always /ruo/ruo. /fn

wo zhe shi sha la ji ying yu a /ll
I wonder that Zhangran won't () me.

Baokao TBYZ miao

Baokao TBYZ xiexiemiao

TBYZ nb miao

CSP-J 2024 is /ruo/ruo
CSP-J 2024 2025 are /qiang/qia
ng

I can't get a prize more than 250 in CSP-S/ll/ll/ll/ll/ll/ll

whk is /ruo/ruo
oi is /ruo/ruo
palying is /qiang/qiang

Should I say "hello" to the friend from luogu?
Who white this passage? AeeE5x? Or others?

Baokao TBYZ miao

Baokao TBYZ xiexiemiao

TBYZ nb miao

I only write 24 lines for this program.
hyw

__int127/bx/bx
unordered/bx/bx
I don't know the name for 3tu/ll
3tu/bx/bx

Zhangsyang/bx/bx
yueluoxingchen/bx/bx
/bx/bx

What am I doing?
hyw

I need a sleep but I don't want to sleep.
/ll
/lq/lq/lq/lq/lq/lq/lq/lq/lq
It's 10:23 now.

hajimi dingdongji manbomanbo

The cpp is 2kb.
div.4?
/bangbangt

I'm sleepy.
*/
#define N 500005
#define V 300005
#define int long long
int n, m, a[N], p[N], lst[V], ans[V];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		p[i] = 1;
		cin >> a[i];
		lst[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		ans[a[i]] += p[i];
		p[lst[a[i]] + 1] += p[i];
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
