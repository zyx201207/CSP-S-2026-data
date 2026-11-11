#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 2e6 + 114 + 514;
bool ds[N], bs[N];
int a[N], cs[N], ans, n, d;
void BL() {
	ans = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		int up = i;
		int ts = 1;
		int brkt = 0;
		cs[i] = 0;
		for(int j = i - 1; j >= 1; j--) {
			if(a[j + 1] - a[j] > d) {
				brkt = j;
				break;
			}
			if(a[up] - a[j] <= d) {
				cs[j] = ts;
			}
			else {
				up = j + 1;
				ts++;
				cs[j] = ts;
			}
		}
		int r = i - 1;
		int l = i - 1;
		while(l > brkt) {
			while(a[r] - a[l] > d && l < r) r--;
			ds[l] = bs[l] = false;
			if(bs[r]) {
				bs[l] = true;
				l--;
				continue;
			}
			if(l + 1 < r && cs[r] == cs[r - 1] && cs[r - 1] != cs[r - 2] && cs[r] == cs[l] - 1) {
				if(ds[r]) {
					bs[l] = true;
					l--;
					continue;
				}
				ans++;
				ds[l] = true;
			}
			else if(l < r && cs[r] != cs[r - 1] && cs[r] == cs[l] - 1 && ds[r] && !bs[r]) {
				ans++;
				ds[l] = true;
			}
			l--;
		}
	} 
	cout << ans << "\n";
}
void solve() {
	cin >> n >> d;
	BL();
	return;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, T;
	cin >> c >> T;
	while(T--) solve();
	
	return 0;
} 

/*
好吧
对于这种大分题目
我选择直接打暴力和特殊性质 

等等
这个 2e6
毫无疑问
SCPT2！
O(n log n)!
不能带任何常数的 n log n!
不管了
先打个暴力再说
先拿 40pts 
好吧
这也太几把难了
我打算直接 O(n^2 log n) 美美跑路了
让我想想
这样的话
我们对于每个 m
做一次这个操作就好了 

等会会让我想想
每个鸟会尝试飞最短的路
让我想想
这个代码应该有点问题
还有 2h 干点部分分应该不难
让我想想
就是说
如果我能一步飞到
那么我一定不会飞两步
啊啊啊
类似了 
不行
让我想想
如果一个点到另一个点是双路径的
那么前面的可达点也一定是双路径的
那么
就是寻找最近的双路径的点
首先
一次能飞到的一定不是双路径的
然后
我们观察超过一个点的
不断寻找一个能够成立 x(i+2)-xi <= d 的 i 位置
或者说寻找最后一个 x(i+2)-xi <= d 的位置
然后这个位置以前可达的点都可以成为双路径的
等等
我是不是无意间想到正解了
让我想想 
啊
谈笑间被第二个小样例卡了
让我想想
这也忒阴间了
让我想想这该怎么做
哦
我想我知道了
我们可以计算某个点一次可以到达的点
两次才可以到达的点
三次才可以到达的点
……
n次才可以到达的点
如果一个点需要可以双路径
那么一次跳跃一定包含超过一个次数相同的点
那么
我们就这么做吧 
让我想想
事实上
我们可以继续简化
因为一次只能跳……
算了
直接做吧
反正我们时间复杂度 O(n^2) 够够的
要打正解以后再说 

7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

哎呀我靠
想拿个 40pts 都这么难
还有 1:30
我们还有时间 
还有 1:17
让我想想
只要打出了这道题
我们就可以放松了
让我想想
显然
这样的话
如果跳一次只有一个路径
而恰巧那个又是正好双路径
那么就是双路径的 

让我想想
其实还挺复杂的
我们需要表示两个量
双路径与超路径 

哎
我们要给暴力程序写对拍了 

哦对了 
tot 3 也是麻烦的情况
让我想想
就是说 
*/
