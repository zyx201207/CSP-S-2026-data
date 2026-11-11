#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5;

long long pre[N + 5];
int a[N + 5];
char c[N + 5];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		pre[i] = pre[i - 1] + a[i];
	}
	
	long long res = 0, le, ri;
	for (int i = 1; i <= n && pre[i - 1] + 1 <= pre[n] / 2; i++) {
		le = pre[i - 1] + 1, ri = min(pre[i], pre[n] / 2);
		int rpos = lower_bound(pre + 1, pre + n + 1, pre[n] - le + 1) - pre, lpos = lower_bound(pre + 1, pre + n + 1, pre[n] - ri + 1) - pre;
		for (int j = lpos; j <= rpos; j++) {
			if (c[i] != c[j]) {
				int lj = max(pre[j - 1] + 1, pre[n] - ri + 1), rj = min(pre[j], pre[n] - le + 1);
				res += rj - lj + 1;
			}
		}
	}
	cout << res << "\n";
	
	return 0;
} 
