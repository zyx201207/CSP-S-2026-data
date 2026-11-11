#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, M = 2e3 + 10; 
long long n, m, ans;
long long a[N], cnt[M][M], sum[N];
bool cmp(int x, int y) {return x > y;}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		long long num = 0;
		while(a[i]) {
			cnt[i][num] = a[i] % 2;
			a[i] /= 2, ++num;
		}
	}
	for(int i = 1; i <= 32; i++) {
		for(int j = 1; j <= n; j++) {
			sum[i] += cnt[i][j];
		}
	}
	sort(sum + 1, sum + 32 + 1, cmp);
	for(int i = 1; i <= 32; i++) {
		if(sum[i] >= m) {
			long long t = pow(2, i);
			ans += t;
		}
	}
	cout << ++ans;
	return 0;
}
