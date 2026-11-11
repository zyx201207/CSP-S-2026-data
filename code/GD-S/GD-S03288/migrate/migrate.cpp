#include<bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

long long c, t;
long long n, d;
long long a[N];

long long dfs(long long l, long long r, long long cnt, long long mi) {
	if(l == r) return cnt == mi;
	if(cnt > mi) return 0;
	long long ans = 0;
	for(long long i = 1;i <= r - l;i++) {
		if(a[l + i] - a[l] <= d) ans += dfs(l + i, r, cnt+1, mi);
	}
	return ans;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(long long i = 1;i <= n;i++) cin >> a[i];
		long long ans = 0;
		for(long long i = 1;i <= n;i++) {
			for(long long j = i + 1;j <= n;j++) {
				long long minn = 0;
				if(i == j) continue;
				long long last = i;
				for(long long k = i+1;k <= j;k++) {
					if(a[k] - a[last] > d) {
						if(last == k - 1) {
							minn = -1;
							break;
						}
						last = k - 1, minn++;
					}
				}
				if(last < j) minn++;
				if(minn == -1) continue;
				long long sum = dfs(i, j, 0, minn);
				if(sum == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
