#include<bits/stdc++.h>
using namespace std;
int n, m, a[200001];
void solve() {
	cin >> n >> m;
	vector <int> ve, ve2;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ve.push_back(a[i]);
	} 
	for (int i = 30; i >= 0; i--) {
		int tmp = 0;
		for (auto x : ve) {
			if (x & (1 << i)) {
				tmp++;
				ve2.push_back(x);
			}
		}
		if (tmp >= m) {
			if (tmp > m) {
				swap(ve, ve2);
				vector <int> ().swap(ve2);
			} else {
				int ans = ve2[0];
				for (int j = 1; j <= m - 1; j++) {
					ans &= ve2[j];
				}
				cout << ans;
				return;
			}
		} else {
			vector <int> ().swap(ve2);
		}
	}
	int ans = ve[0];
	for (int j = 1; j <= m - 1; j++) {
		ans &= ve[j];
	}
	cout << ans;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
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

首先，我们会贪心的让最高位尽可能大。

设初始为一个集合

对这个集合，我们发现：如果其中有 q(>=m) 个数二进制下从左往右第i位上是 1，那么答案就肯定可以有一位是1了。

然后将这些第i位上是1的所有数收集起来，i<-i+1，重复上述过程……

如果某一次集合大小为 m，输出它们的按位与。

如果到了最后集合大小还是>m，随机m个元素，输出它们的按位与。 

时间复杂度 O(31n)。 

*/
