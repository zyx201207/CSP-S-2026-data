#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long ans;
long long used = 0;
long long a[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	long long st = 1;
	for(long long ed = 1; ed <= n; ed++){
		used += ((ed - 1) - st + 1) * (a[ed] - a[ed - 1]);
		while(st < ed && used > m){
			used -= a[ed] - a[st];
			st++;
		}
//		cout << st << " " << ed << " " << used << "\n";
		ans = max(ans, ed - st + 1);
	}
	
	cout << ans << "\n";
	
	return 0;
}
