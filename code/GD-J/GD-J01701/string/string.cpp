#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
int n, len[N];
char c[N];
long long ans;
bool a1 = 1;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> len[i] >> c[i];
		if (i > 1)
			if (c[i] != c[i - 1])
				a1 = 0;
	}
	if (a1) {
		cout << 0 << endl;
		return 0;
	} else {
		int l = 1, r = n;
		while (l <= r) {
			if (c[l] != c[r]) {
				if (len[l] > len[r]) {
					ans += len[r];
					len[l] -= len[r];
					len[r] = 0;
					r--;
				} else if (len[l] < len[r]){
					ans += len[l];
					len[r] -= len[l];
					len[l] = 0;
					l++;
				} else {
					ans += len[l];
					len[l] = 0;
					len[r] = 0;
					l++;
					r--;
				}
			} else {
				if (len[l] > len[r]) {
					len[l] -= len[r];
					len[r] = 0;
					r--;
				} else if (len[l] < len[r]){
					len[r] -= len[l];
					len[l] = 0;
					l++;
				} else {
					len[l] = 0;
					len[r] = 0;
					l++;
					r--;
				}
			}
		}
		cout << ans << endl;
		return 0;
	}
}

