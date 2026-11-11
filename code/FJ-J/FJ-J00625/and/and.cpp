#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10,M = 1010;
int n, m, a[N];
long long f[M][M];
bool A = true;
//bool lowbit(int x) {
//	int a = x;
//	a += 1;
//	if(a == 1 || a== 2||a == 4)
//		return true;
//	while(a != 1) {
//		if(a % 2 == 0) return false;
//		a /= 2;
//	}
//	return true;
//}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	if(n <= 1000) {
		f[1][1] = a[1];
		for(int i = 1; i <= n; i ++)  {
			f[i][1] = a[i];
			for(int j = 1; j < i; j ++) {
				for(int k = 1; k < m; k ++) {
					f[i][k + 1] = max(f[i][k], f[j][k] & a[i]);
				}
			}
		}
		cout << f[n][m];
		return 0;
	}
	int ans;
	sort(a + 1, a + n + 1, greater<int>());
	ans = a[1];
	for(int i = 2; i <= m; i ++) ans &= a[i];
	cout << ans;
	return 0;
}
