#include <bits/stdc++.h>
using namespace std;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 5;
using ll = long long;
const int inf = 5e7;


int n, m;
int c[maxn];
struct nod {
	int b[40];//每个数的二进制位 
	int a;
}p[maxn];
int ans = 0;
ll cnt = 0;
bool cmp(nod x, nod y) {
	return x.a < y.a;
}
void dfs(int u, int sum, int k) {
//	cout << sum << " " << k << "\n";
	if (sum == 0) return;
	if (cnt == inf) {
		if (k == m) ans = max(ans, sum);
		cout << ans;
		exit(0);
	}
	if (k == m) {
		ans = max(ans, sum);
//		cout << sum << "\n";
		return;
	}
	for (int i = u + 1; i <= n; ++i) {
//		cout << (sum & p[i].a) << " " << k << "\n";
		++cnt;
		dfs(i, (sum & p[i].a), k + 1);
	}
}
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].a;
	}
	for (int i = 1; i <= n; ++i) {
		dfs(i, p[i].a, 1);
	}
	cout << ans << "\n";
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	AC;
	solve();
//	cin >> n >> m;
//	for (int i = 1; i <= n; ++i) {//n log n
//		cin >> p[i].a;
//		int x = p[i].a;
//		int t = 0;
//		while (x) {//log n 
//			++t;
//			if (x % 2 == 1) {
//				c[t] = 1;
//			}
//			x /= 2;
//		}
//		for (int j = 1; j <= t; ++j) {//log n
//			p[i].b[j] = c[t - j + 1];
//		}
//	}
//	sort(p + 1, p + 1 + n, cmp);
//	/*
//	首先 查找一个数的二进制的时间复杂度是O(log n)
//	我们把每个数的二进制位求出来
//	*/
//	for (int i = 1; i <= m; ++i) {
//		
//	}
	
	
	return 0;
}
