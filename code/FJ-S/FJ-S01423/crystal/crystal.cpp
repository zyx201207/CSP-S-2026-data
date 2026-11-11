#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 2e18;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	vector<LL> a(n+1, -INF), del(n+2);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	if(n == 1){
		cout << "1\n";
		return 0;
	}
	
	sort(a.begin()+1, a.end());
	
	bool caseAB = true;
	LL d = a[2] - a[1];
	for(int i = 3; i <= n; i++){
		if(a[i] - a[i-1] != d){
			caseAB = false;
			break;
		}
	}
	
	int ans = 0;
	
	if(caseAB){
		for(int i = 1; i <= n; i++){
			int l = 0, r = i + 1;
			int mid = (l+r) >> 1;
			while(l + 1 < r){
				mid = (l+r) >> 1;
				if((i-mid) * (i-mid+1) / 2 * d > m){
					l = mid;
				} else {
					r = mid;
				}
			}
			ans = max(ans, i - r + 1);
		}
		cout << ans << '\n';
		return 0;
	}
	
	for(int i = 1; i <= n; i++){
		int l = 0, r = i + 1;
		int mid = (l+r) >> 1;
//		cout << i << '\n';
		while(l + 1 < r){
			mid = (l+r) >> 1;
			LL val = 0;
			for(int j = i-1; j >= mid; j--){
				val += a[i] - a[j];
			}
			if(val > m){
				l = mid;
			} else {
				r = mid;
			}
//			cout << mid << ' ' << val << '\n';
//			cout << l << ' ' << r << ' ' << mid << '\n';
		}
		ans = max(ans, i - r + 1);
//		cout << r << ' ' << ans << '\n';
	}
	cout << ans << '\n';
	return 0;
}
