#include <iostream>
#include <cstdio>
using namespace std;
long long a[10010];
long long n, m, cnt,sum;
int main() {
	freopen("crystal.in", "w", stdin);
	freopen("crystal.out", "r", stdout);
	cin >> n >> m;
	for (long long i = 1; i<=n; i++) {
		cin >> a[i];
		cnt += a[i];
	}
	long long x = 1, wxl = 0;
	long long mid = cnt/n;
	for (long long i = 1; i <= m;) {
		if (sum + wxl==n&&m>=1) {
			mid++;
		}
		for (long long j =x;j<=n; j++) {
			
			if (a[j] == mid) {
				sum++;
				break;
			}
			if (a[j] > mid) {
				wxl++;
				break;
			}
	    	if(a[j]<mid){
				a[j]++;
				m--;
			}
		}
	}
	cout << sum << endl;
	return 0;
}

