#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10;
long long n, m, ans = 1;
long long a[N], p[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	bool flag = 0;
	for (long long i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] != i) flag = 1;
	}
	sort(a + 1, a + n + 1);
	for (long long i = 1; i <= n; i++) p[i] = abs(a[i] - a[i - 1]);
	if (flag == 0){
		long long cnt = 0;
		for (long long i = 1; i <= n; i++) cnt += a[i];
		cnt += m;
		cout << cnt / n;
		return 0;
	} 
	for (long long i = 2; i <= n; i++){
		if (m >= (i - 1) * p[i]){
			m -= (i - 1) * p[i];
			ans++;
		}
	}
	cout << ans;
	return 0;
}
