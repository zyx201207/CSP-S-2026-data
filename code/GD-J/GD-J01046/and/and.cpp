#include<bits/stdc++.h>
using namespace std;
#define i64 long long
const int N = 2e5 + 10;

int n, m, a[N], t[35], mn[35], sum[35][N], ans = 0;
bool b[N][35];

void init (int i, int a) {
	for (int k = 2, j = 1; j <= 30; j++) {
		sum[j][i] = sum[j][i - 1] + a % 2;
		b[i][j] = a % 2;
		if (a % 2) mn[j] = min(mn[j], i);
		a >>= 1;
	} 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	memset(mn, 0x3f, sizeof(mn));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		init(i, a[i]);
	}
	for (int i = 1, j = 30; j >= 1; j--) {
		if (sum[j][n] - sum[j][i - 1] >= m) {
			for (int _ = i; _ <= n; _++) {
				if (b[_][j] == 1) {
					i = _;
					break;
				}
			}
			ans += 1 << (j - 1);
		}
	}
	cout << ans << '\n';
	
	return 0;
}

