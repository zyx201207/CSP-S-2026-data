#include<bits/stdc++.h>
using namespace std;
#define i64 long long
const int N = 2e5 + 10;

int n, a[N], b[N], mid, cnt = 1;
char c[N], d[N];
i64 m, sum[N], tot, ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string4.in", "r", stdin);
	freopen("string4.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> b[i] >> d[i];
		sum[i] = sum[i - 1] + b[i];
		tot += b[i];
	}
	for (int i = 1; i <= n; i++, cnt++) {
		if (sum[i - 1] < (tot + 1) / 2 && sum[i] >= (tot + 1) / 2) {
			if ((tot + 1) / 2 != sum[i - 1] + 1) {
				mid = cnt;
				a[cnt] = tot / 2 - sum[i - 1]; 
				c[cnt] = d[i];
				if ((tot + 1) / 2 != sum[i]) {
					a[++cnt] = sum[i] - (tot + 1) / 2;
					c[cnt] = d[i];
				}
			}
			else if ((tot + 1) / 2 != sum[i]) {
				mid = cnt - 1;
				a[cnt] = sum[i] - (tot + 1) / 2;
				c[cnt] = d[i];
			}
			else {
				mid = cnt - 1;
				cnt--;
			}
		}
		else {
			a[cnt] = b[i];
			c[cnt] = d[i];
		}
	} cnt--;
//	for (int i = 1; i <= cnt; i++) {
//		cout << a[i] << ' ';
//	}cout << '\n';for (int i = 1; i <= cnt; i++) {
//		cout << c[i] << ' ';
//	}cout << '\n';
//	cout << tot << ' '<< cnt << ' ' << mid << '\n';
	for (int i = 1, j = cnt; i <= mid && j >= mid + 1; ) {
		if (c[i] != c[j]) {
			if (a[i] < a[j]) {
				a[j] -= a[i];
				ans += a[i];
				i++;
			}
			else if (a[i] > a[j]) {
				a[i] -= a[j];
				ans += a[j];
				j--;
			}
			else {
				ans += a[i];
				i++, j--;
			}
		}
		else
			i++, j--;
	}
	
	cout << ans << '\n';
	
	return 0;
}

