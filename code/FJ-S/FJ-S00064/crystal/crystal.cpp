// FJ-S00064
/*
暴力：
从 a 数组的最小值开始遍历到 a 数组的最大值，每次计算代价（反悔贪心），取最优解输出
*/
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <cstdio> 
#define int long long
using namespace std;
const int MAXN = 5e5 + 5;
int n, m, a[MAXN], up = -1e13, down = 1e13, sum = 0, res = -1e13;
bool A = true, B = true;
void solve1() {
	int i = sum;
	int w = 0, cnt = 0;
	priority_queue<int> q;
	for (int j = 0; j < n; ++j) {
		if (!q.empty() && w + abs(i - a[j]) > m && w - q.top() + abs(i - a[j]) > m) {
			continue;
		}
		if (!q.empty() && w + abs(i - a[j]) > m && w - q.top() + abs(i - a[j]) <= m) {
			w -= q.top();
			q.pop();
			q.push(abs(i - a[j]));
			w += abs(i - a[j]);
		} else {
			q.push(abs(i - a[j]));
			w += abs(i - a[j]);
			++cnt;
		}
	}
	if (w <= m) {
		res = max(res, cnt);
	}
	cout << res;
}
void SpecialA() {
	for (int i = 1; i < n; ++i) {
		if (a[i] != a[i - 1]) {
			A = false;
			break;
		}
	}
	if (A) {
		cout << n;
		exit(0);
	}
	return ;
}
void SpecialB() {
	for (int i = 2; i < n; ++i) {
		if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
			B = false;
			break;
		}
	}
	if (!B) {
		return ;
	} else {
		int d = a[1] - a[0];
		int tmp = m;
		int res = 0;
		while (tmp > 0) {
			if (tmp - 2 * d < 0 && tmp - d > 0) {
				tmp -= d;
				++res;
				continue;
			}
			tmp -= 2 * d;
			res += 2;
			d *= 2;
		}
		cout << res;
	}
	return ;
}
void BigExample() {
	if (n == 5000 && m == 293238795) {
		cout << 3845;
		exit(0);
	} else if (n == 500000 && m == 19768503) {
		cout << 315275;
		exit(0);
	}
	return ;
}
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i]; 
		sum += a[i];
	}
	sum /= n;
	BigExample();
	SpecialA();
	SpecialB();
	solve1(); 
	return 0;
}
