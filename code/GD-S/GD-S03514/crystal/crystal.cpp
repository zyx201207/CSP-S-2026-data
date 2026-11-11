#include <bits/stdc++.h>
#define inc(i, l, r) for(long long i = l; i <= r; ++i)
#define dec(i, l, r) for(long long i = l; i >= r; --i)
using namespace std;

const int N = 5 * 1e5 + 5;

long long n, m, a[N];
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	inc(i, 1, n) {
		cin >> a[i];
	}
	
	if(n <= 5000) {
		long long k = 0, ans = 0, cnt = 0;
		inc(i, 1, n) {
			k = 0, cnt = 1;
			dec(j, i - 1, 1) {
				if(k + a[i] - a[j] <= m) {
					k += a[i] - a[j];
					cnt++;
				}
			}
			ans = max(cnt, ans);
		} 
		cout << ans << '\n';
	} else {
		bool A = 1, B = 1;
		inc(i, 1, 20) if(i != a[i]) A = 0;
		
		long long d = a[2] - a[1];
		inc(i, 3, 20) if(a[i] - a[i - 1] == d) B = 1;
		
		if(A == 1) {
			int k = 1, now = 0;
			inc(i, 1, n) {
				if(now + k <= m) {
					now += k;
					k += 1;
				} else break;
			}
			cout << now + 1 << '\n';
		} else if(B == 1) {
			int times = 1;
			while(times * d <= m) {
				times++;
			} 
			cout << times << '\n';
		}
	}
	return 0;
} 
