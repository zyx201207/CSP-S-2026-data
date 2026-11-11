#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node {
	int x;
	char ch;
	void input() {
		cin >> x >> ch;
//		cout << ch;
	}
	void output() {
		cout << x << ' ' << ch << '\n';
	}
} a[200001];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		a[i].input();
	} 
	int l = 1, r = n;
	node tmpl = {0, ' '};
	node tmpr = tmpl;
	while (l < r) {
//		cout << 1 << '\n';
		if (!tmpl.x) { 
			tmpl = a[l];
		}
		if (!tmpr.x) {
			tmpr = a[r];
		}
		if (tmpl.x > tmpr.x) {
			ans += (tmpl.ch != tmpr.ch) * tmpr.x;
			tmpl.x -= tmpr.x;
			tmpr.x = 0;
			r--;
		} else {
			ans += (tmpl.ch != tmpr.ch) * tmpl.x;
			tmpr.x -= tmpl.x;
			tmpl.x = 0;
			l++;
			if (!tmpr.x) {
				r--;
			} 
		}
//		cout << l << ' ' << r << '\n'; 
//		tmpl.output();
//		tmpr.output();
	} 
	cout << ans;
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--) {
		solve();
	}
} 

/*

现在 
我感到很迷茫和无力
现在的生活，真的是我想要的吗
虽然来到了一所好学校，但并没有过得像以前一样快乐呢
… 
我是真的尽力了
如果有一天
我可以撤回之前的选择，那我会忘掉【数据删除】的
一想起【数据删除】和过去的事情
我都倍感后悔，很想告诉小时候的自己，不要去这么做
可是，还是这么做了
于是我就只能后悔
陷入无尽的痛苦的回忆中，无法脱身，直到现在
…
我还说些什么好呢？我也不清楚
还是祝愿今天能拿到个好成绩吧
那就真没啥要说的了

3 2 a
2 b
1 c
*/
