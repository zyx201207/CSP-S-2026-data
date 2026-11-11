#include <bits/stdc++.h>
using namespace std;
long long a[500050], b[500050];
long long n, m;
int main(){
	freopen ("crystal.in", "r",stdin);
	freopen ("crystal.out", "w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		b[i] = a[i + 1] - a[i];
	}
	b[n] = 100000000000000050;
	int ppt = 0;
	int i = 1, j = 1, now = 0, cnts = 0, ans = 1;
	while (j < n){
		while (now + b[j] * (j - i + 1) <= m && j < n){
			now += b[j] * (j - i + 1);
			cnts += b[j++];
		}
		ans = max(ans, j - i + 1);
		now -= cnts;
		cnts -= b[i++];
	}
	cout << ans;
	fclose (stdin);
	fclose(stdout);
	return 0;
}
