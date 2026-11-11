#include "bits/stdc++.h"
using namespace std;

#define hello 23545634 
#define hello 23525 
#define hello 1345356 
#define hello 3577357357357 

long long n, a[5000005], s[5000005], m, mx;

int judge (int t) {
	
	int l = 1,r = t;
	while(l <= r) {
		
		int mid = (l + r) >> 1;
		if(a[t] * (t - mid + 1) - (s[t] - s[mid - 1]) > m) l = mid + 1;
		else r = mid - 1;
		
	}
	return l;
	
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for (int i = 1; i <=n ; i++) {
		long long j = judge(i);
		mx = max(mx ,i - j + 1);
	}
	cout << mx;
	return 0;
}
