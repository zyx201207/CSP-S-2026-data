#include<bits/stdc++.h>
using namespace std;

int n;
long long m, a[500010], ans;
long long minn = LLONG_MAX, maxx = LLONG_MIN;

bool check(long long x){
	long long tot = 0, sy = m;
	int pos = upper_bound(a, a + n, x) - a - 1;
	for(int i = pos; i >= 0; i --){
		if(a[i] == x) tot ++;
		else if(x - a[i] <= sy){
			tot ++;
			sy -= x - a[i];
		} else break;
	} 
	if(tot > ans){
		ans = tot;
		return true;
	}
	return false;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int ok = 1;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		minn = min(minn, a[i]);
		maxx = max(maxx, a[i]);
		if(a[i] != a[i-1] + 1) ok = 0;
	}
	sort(a, a+n);
	if(ok){
		m *= 2;
		int i = sqrt(m);
		if(i*(i+1) <= m) cout << i + 1;
		else cout << i;
		return 0;
	}
	if(m >= 1e9){
		// meiju neng liang zhi
		long long l = minn, r = maxx + m / n, mid;
		while(l <= r){
			mid = l + (r - l) / 2;
			if(check(mid)){
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
	} else {
		for(int i = minn; i <= maxx; i ++){
			check(i);
		}
	}
	cout << ans;
	return 0;
} 
