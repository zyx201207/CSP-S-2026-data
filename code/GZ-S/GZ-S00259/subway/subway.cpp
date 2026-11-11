//GZ-J00269，孟杰锐， 贵阳市第一实验中学
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int t, a, b, c, d, x, y, n, m, cnt1, cnt2;
int z[N], v[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> t >> a >> b >> c >> d;
	
	for (int i = 1; i <= b; i++) {
		cin >> z[i];
		cnt1 += z[i];
	}
	
	for (int i = 1; i <= a; i++) {
		cin >> x;
	}
	for (int i = 1; i <= x; i++) {
		cin >> v[i];
		cnt2 += v[i];
	}
	
	for (int i = 1; i <= x; i++) cin >> n >> m;
	
	cout << cnt1 << "\n" << cnt2;
	
	return 0;
}
