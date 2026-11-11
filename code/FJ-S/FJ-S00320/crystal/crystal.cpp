#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N], b[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = n; i >= 1; i--) b[i] = a[n] - a[i];
	long long max1 = -0x3f3f;
	for (int j = 2; j <= n; j++){
		long long s = 0, nx = 1;
		long long aim = b[j];
		for (int i = j - 1; i >= 1; i--){
			s += (b[i] - aim);
			if (s > m) break;
			nx++;
		}
		max1 = max(max1, nx);
	}
	cout << max1;
	return 0;
}
