/*
欢迎关注洛谷 kaikai_qwq(uid = 1106246) qwq

- 空间炸了 / 小了吗？
- 边界特判了吗？
-  多测清空了吗？
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
//	freopen("travel.in", "r", stdin);
//	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
	} else {
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << "1";
			char a1 = s1[2], a2 = s2[2];
			if (a1 <= 'C' && a2 <= 'C' || a1 >= 'D' && a2 >= 'D') {
				cout << "1";
				if (a1 > a2) swap(a1, a2);
				if (a1 == 'A' && a2 == 'B' || a1 == 'B' && a2 == 'C' || a1 == 'D' && a2 == 'F') cout << "1";
				else cout << "0";
			} else cout << "00";
		} else cout << "000";
	}
	return 0;
} 
/*
YZ 初一采集前来报到！ 

我想上 HN 迷惑行为大赏 /kel 

游记

8:30 考官：密码还没来。

8:33 密码来了，Trick||Treat! 

8:34 开文件。

8:38 开始写 T1。

8:40 写完，小样例怎么没过啊（

8:42 改完

8:48 写完 T2，双指针版子

8:50 大样例都过了 

9:03 写完 T3，这不是从高到低位贪心一下，如果当前位为 1 的 >= m 直接从小到大贪心选

9:05 过了大样例

bushi T1T2T3 怎么这么水

9:20 哎 T4 是不是。。。（看我 T4 代码注释）

9:31 调完 

9:34 大样例都过了，可恶怎么没有行末空格并且还有换行，害我还得改一下

AK 了！

感觉 <<<< 2025，毕竟去年我 VP 的时候只有 364 分 

建议评级：

T1：无，红 
T2：贪心、双指针，橙 
T3：贪心、位运算，黄 
T4：DP、拓扑排序、图论建模，绿 

100 + 100 + 100 + 100 = 400 qwq

著名：周家正（

上午都 AK 了，下午应该能 200+ 吧 qwq 

去玩小恐龙和 surf 了 qwq 

下午一定要过 T1T2 啊 qwq 

我要 7 钩 qwq 

拿不了 J 1 等了，因为是 J 1 级 qwq

qwq 
*/
