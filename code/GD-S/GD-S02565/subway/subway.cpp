#include <iostream> 
#include <cstdio>
using namespace std;
long long c,n,m,d,q;
long long w[10010], k[510], a[510][510], t[510][510];
long long wxl(long long x, long long y) {
	long long z = 1, sum = 100000, cnt=100000;
	long long d, e,b;
	for (long long i = 1; i<=n; i++) {
		for (long long j = 1; j<=k[i]; j++) {
			if(a[i][1]!=1) {
				i++;
				break;
			}
			while (a[i][j] == y) {
				if (sum > t[i][j] + t[i][1]) {
					sum = t[i][j] + t[i][1];
					d = a[i][1];
				}
			}
		}
	}
	if(d == x) {
		sum += w[x] + w[y];
		return sum;
	}
	for (long long i = 1; i<=n; i++) {
		for (long long j = 1; j<=k[i]; j++) {
			if (a[i][j] == d){
				if(cnt > t[i][j]) {
					cnt += t[i][j] + t[i][1];
					d = a[i][1];
				}
			}
		}
	}
	sum += cnt;
	if(d == x) {
		sum += w[x] + w[y];
		return sum;
	}
	for (long long i = 1; i<=n; i++) {
		for (long long j = 1; j<=k[i]; j++) {
			if(a[i][j] == x) {
				sum += w[x] + w[y] + t[i][j];
				return sum;
			}
		}
	}
}
int main() {
	freopen("subway.in", "w", stdin);
	freopen("subway.out", "r", stdout);
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1; i<=m; i++) {
		cin >> w[i];
	}
	for (long long i = 1; i<=n; i++) {
		cin >> k[i];
		for (long long j = 1; j<=k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (long long i = 1; i<=q; i++) {
		long long x, y;
		cin >> x >> y;
		cout << wxl(x, y) << endl;
	}
	return 0;
}

