#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500005];
long long ans = 1;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for(long long i = 1;i <= n;i++) cin >> a[i];
	if(n > 30000){
		int t = a[n] - a[n - 1], t2 = 0, ans = 1;
		while(t2 <= m){
			t2 += ans * t;
			ans++;
		}
		cout << ans;
	}
	sort(a + 1, a + n + 1);
	for(long long i = n;i > ans;i--){
		long long cnt = 1, sum = 0;
		for(long long j = i - 1;j >= 1;j--){
			sum += a[i] - a[j];
			if(sum <= m) cnt++;
			else break;
		}
		if(cnt > ans) ans = cnt;
	}
	cout << ans;
	return 0;
}

