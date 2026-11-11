/* 
我把 CSP-J 的日志都写在 T1 了，%%%，hyw，希望高分吧。
我上次考试的时候还是太糖了，所以这次想上 HN 迷惑行为大赏，冰冰冰。  
我的 CSP-J 日志:
2026/10/31 7:46 进入考场
2026/10/31 7:53 打完基础框架
2026/10/31 8:14 发现文件夹名字写错了，赶紧改 oT_To
2026/10/31 8:20 被 CCFNOI 的广播吓到了 opps!!
2026/10/31 8:30 居然有人的身份证掉了 666！ 
2026/10/31 8:31 发题了，开始写 T1 
2026/10/31 8:39 写完 T1 代码，发现用不了 #define int long long，但是之后的可以用。 
2026/10/31 8:44 切掉 T1! ^_^ 
2026/10/31 8:48 T2 好水
2026/10/31 8:54 发现 T2 不水，直接 T了 oT_To
2026/10/31 9:00 不写 T2 了，直接写 T3,但是 T2 也拿了 68pts oA_Ao
2026/10/31 9:23 拿了一些 T3 的部分分，继续想 T2，不过终于想出来了 ^_^
2026/10/31 10:00 感觉自己还是太糖了，直接写 T3 去了。oX_Xo
2026/10/31 10:15 T3 拿了 50pts 就去看 T4 了
2026/10/31 10:30 打完 T4 暴力 
2026/10/31 10:54 尝试思考 T4 正解
2026/10/31 11:12 尝试失败 X_X 
2026/10/31 11:33 检查完了，预计本次 100 + 68? + 75? + 48 = 291?
*/
#include <bits/stdc++.h>
using namespace std;
int ccc(char c) {
	if(c == 'A' || c == 'B' || c == 'C') return 1;
	else return 2;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		cout << 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << 1;
			if(ccc(s1[2]) == ccc(s2[2])) {
				cout << 1;
				char a = s1[2], b = s2[2];
				if(a == 'F') a = 'E';
				if(b == 'F') b = 'E';
				if(abs(int(a) - int(b)) == 1) cout << 1;
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
