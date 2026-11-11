#include<bits/stdc++.h>
using namespace std;
long long n, m;
unsigned long long sum = 0;
long long a[500005], maxx = -1;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	long long j = n;
	for(long long i = n; i >= 1; i--) {
		while(sum + (a[i] - a[j - 1]) <= m && j - 1 > 0) {
			j--;
			sum += (a[i] - a[j]);
		}	
		//cout << j << " " << sum << endl;
		maxx = max(maxx, (i - j + 1));
		if (j < i) {
			sum -= (a[i] - a[i - 1]) * (i - j);
		}
	}
	cout << maxx << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
