#include <bits/stdc++.h>
using namespace std;
long long a[510000];
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	int ans = 0;
	long long sum = 0;
	for (int i = 1, j = 1; i <= n; i++){
		sum += 1ll * (a[i] - a[i - 1]) * (i - j);
		while (j <= i && sum > m){
			sum -= (a[i] - a[j]);
			j++;
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans << '\n';
	return 0;
} 
