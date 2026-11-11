#include <bits/stdc++.h>
using namespace std;

long long n, m, a[500005], sum[500005] = {0};

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i++)
		sum[i] = sum[i - 1] + a[i];
	long long ans = 1;
	for(long long i = 2;i <= n;i++){
		long long l = 1, r = i + 1, bs = i;
		while(l + 1 < r){
			long long mid = (l + r) / 2;
			if((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m)
				r = mid, bs = mid;
			else
				l = mid + 1;
		}
		if((i - l + 1) * a[i] - (sum[i] - sum[l - 1]) <= m)
			bs = l;
		ans = max(ans, i - l + 1);
	}
	cout << ans << endl;
	return 0;
} 
