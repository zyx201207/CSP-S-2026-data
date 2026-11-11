#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> a;
int tcb[31] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 
		   4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 
		   1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 
		   67108864, 134217728, 268435456, 536870912, 1073741824};
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	a.resize(n + 5);
	bool Aflag = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		bool ct;
		for (int i = 0; i < 31; i++) {
			if (tcb[i] == (a[i] + 1)) {
				Aflag = 1;
				ct = 1;
				break;
			}
		}
		if (ct) continue;
		Aflag = 0;
	}
	/// 特判
	//// 测试点 6
	if (m == 1) {
		int a6[n + 3];
		for (int i = 0; i < n; i++) a6[i] = a[i];
		sort(a6, a6 + n);
		cout << a6[n - 1];
		return 0;
	}
	//// 测试点 7
	if (m == n) {
		int ans = a[0];
		for (int i = 1; i < n; i++) {
			ans = ans & a[i];
		}
		cout << ans;
		return 0;
	}
	//// 测试点 13 (特殊性质 A)
	if (Aflag) {
		int a13[2000005];
		for (int i = 0; i < n; i++) a13[i] = a[i];
		sort(a13, a13 + n);
		int ans = a13[n - 1];
		//cout << (a13[n - 1] & a13[n - 2]);
		for (int i = n - 1; i >= n - m; i--) {
			ans &= a13[i];
		}
		cout << ans;
		return 0;
	}
	//// 测试点 8 - 10
	if (m == 2) {
		long long makesi = -2147483647;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				makesi = max(makesi, (long long)(a[i] & a[j]));
			}
		}
		cout << makesi;
		return 0;
	}
	///// 截至目前 30pts /////
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

