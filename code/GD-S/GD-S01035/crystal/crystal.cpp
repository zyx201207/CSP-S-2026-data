#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, ans = 1;
long long m, a[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int j = -1, k = -1;
	long long sum = 0, cnt = 0;
	for(int i = 2; i <= n; i++) {
		if(a[i] - a[i - 1] > m) {
			k = j = -1, cnt = 0;
			continue;
		}
		k = i - 1, cnt++, sum += cnt * (a[i] - a[i - 1]);
		if(j == -1) j = k;
		else {
			while(sum > m && j < k) 
				sum -= a[i] - a[j], j++, cnt--;
		}
		ans = max(ans, k - j + 2);
	}
	cout << ans;
	
	return 0;
} 
