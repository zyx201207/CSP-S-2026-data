#include <bits/stdc++.h>
using namespace std;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll = long long;
const int maxn = 5e5 + 5;
//请注意：存储数组内的值要开long long
 

ll n, m;//n <= 5e5, m <= 1e18 
ll a[maxn];//a_i <= 1e12
bool flag_a, flag_b;//特殊性质 A & B 
ll cf[maxn];//差分数组 
ll qz[maxn];//差分数组前缀和数组 
void solve1() {
	//n^2做法 
	int ans1 = 0;//记录答案 
	for (int i = 1; i <= n; ++i) {
		//i 表示计算起点
		//排序后会选取连续的区间进行“消除合并”
		//设答案为x 则 选中的每个点的加数为x - a_i
		int k = 0;//记录临时答案 
		ll t[maxn] = {};
		for (int j = 1; j <= n; ++j) {
			t[j] = a[j];
		}
		for (int j = i; j < n; ++j) {
			k += cf[j] * (j - i + 1);
			if (k > m) {//这里的回溯只会进行1次，for + while 共 O(2n) 为 O(n) 
				int p = j - 1;
				while (cf[p] == 0) --p;
//				cout << p << "\n";
				for (int ls1 = i; ls1 <= p; ++ls1) {
					t[ls1] = a[j];
				}
				break;
			}
		}
		int p = 0;
		for (int j = 1; j <= n; ++j) {
//			cout << t[j] << " ";
			if (t[j] != t[j - 1]) p = 1;
			else ++p;
			ans1 = max(ans1, p);
		}
//		cout << "\n";
	}
	cout << ans1 << "\n";
}
void solve2() {
	//O(n log n)的尝试做法
	int k = 0;
	int last = 1;//上一截断点 
	int ans2 = 0;
	for (int i = 1; i <= n; ++i) {
		k += (i - last + 1) * cf[i];
		if (k > m) {
			ans2 = max(ans2, i - last + 1);
			int t = last;
			while (k > m) {
				k -= qz[i] - qz[t];
				++t;
			}
			last = t;
		}
	} 
	cout << ans2 << "\n";
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	AC;
	cin >> n >> m;
	flag_a = flag_b = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] != i) {
			flag_b = 0;
		}
		if (i > 2) {
			if (a[i] - a[i-1] != a[i-1] - a[i-2]) {
				flag_a = 0;
			}
		}
	}
	if (flag_b) {
		//特殊性质B 测试点16~18 
		//若a[i] = i
		//计算m = 1 + 2 + ... + ?
		//m = n(n+1)/2, m向下取整
		ll p = 0;
		for (int i = 1; true; ++i) {
			p += i;
			if (p > m) {
				p = i - 1;
				break;
			}
		}
		cout << p << "\n";
		return 0;
	}
	if (flag_a) { 
		//特殊性质A 测试点13~15 
		int t = a[2] - a[1];
		//那么数列为1t, 2t, 3t...
		ll p = 0;
		for (int i = 1; true; ++i) {
			p += i;
			if (p * t > m) {
				p = i - 1;
				break;
			}
		}
		cout << p << "\n";
		return 0;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i < n; ++i) {
		cf[i] = a[i + 1] - a[i];//计算差分 
	}
	for (int i = 1; i < n; ++i) {
		qz[i] = qz[i-1] + cf[i];
	}
//	if (n <= 5000) {
		//O(n ^ 2)做法 
//		n <= 5, m <= 10
//		|a_i| <= 20
//		solve1();
//		return 0;
//	}
	//至此，已经写完了9 + 2*3的测试点，共15个点，75pts，虽然不一定对
	//n = 5000的大样例过了
	//本质是枚举起点，计算 k = \sum_{i = start}^{end} (i - start + 1) * cf_i 
	//k <= m 找出最大的k，end是k > m时的i - 1
	solve2();
	//应该是正解， O (n) ， 但排序O(n log n) 
	
	
	
	return 0;
}
//注意到只能+
//x x xxx
//rp++  rp += inf 
