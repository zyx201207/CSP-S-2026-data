#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
const int N = 2e5 + 5;
int n, m, x, y;
char k, z;
int a[N];
inline bool jud(char k, char z) {
	if ('A' <= k && k <= 'C' && 'A' <= z && z <= 'C') 
		return 1;
	if ('D' <= k && k <= 'E' && 'D' <= z && z <= 'E') 
		return 1;
	return 0;
}
void solve() {
	cin >> n >> m >> k >> x >> y >> z;
	if (n == x) {
		cout << 1;
		if (m == y) {
			cout << 1;
			if (jud(k, z)) {
				cout << 1;
				if (abs((int)(k) - (int)(z)) == 1) {
					cout << 1;
				} else 
					cout << 0;
			} else 
				cout << "00";
		} else 
			cout << "000";
	} else 
		cout << "0000";
	cout << "\n";
}
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
//	cin >> t;
	while (t --) {
		solve();
	}
	return 0;
}




/*
Traveling Note

CSP-J游记
不知道读者是何时看到的
我就是那个在去年考S组闲着往代码里放五子棋的

sto CCF orz
sto ztx orz
sto cgy orz
sto smy orz
sto 出题人 orz
sto 评测姬 orz 

[08:19] 开始记录 玮神又双叒叕和我一个考场
注意到场上LSWGY有至少3人（我，我不认识的，玮神即zzztx（他的Luogu就不放了））

[08:30] 开考 密码Trick||Treat! 
我的代码能力真的退化了??

[08:47] 过T1??

[09:47] 调不动T2 看T3T4 怎么一道图论都没有啊??

[10:01] ……不想写了 100 + 0 + 25 + 0 = 125??

[10:40] 我?
滚去写部分分吧

[10:53] T2部分分写完 100 + 56 + 25 + 0 = 181??

[11:21] T3争了一下 100 + 56 + 25(玄学为50) + 0 = 181 || 206??

[11:25] T3那个部分分?不是玄学 100 + 56 + 50 + 0 = 206?? 依旧上不了1=线 我是个残废??

[11:44] T4争不了了??跑路了兄弟 跑路了
我是Luogu1283849
和HN-J00200以及HN-J00179(189?)一起来的
前者是和我同时开始学的 后者是今年才学的萌新
祝CSP2026RP++

[11:59] S组再见?? 我会留五子棋的

我喜欢SXY
*/ 
