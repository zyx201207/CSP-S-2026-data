#include <bits/stdc++.h>
#define int long long
using namespace std;

int check(const vector<int> &sz, int a, int b){
	int sum = 0;
	
	for(int i = 1; i <= b; ++ i)
		sum += sz[i];
	
	int ans = b * sz[b] - sum;
	
	for(int i = b + 1; i <= a; ++ i)
		sum += sz[i],
		sum -= sz[i - b],
		ans = std::min(ans, b * sz[i] - sum);
	
	return ans;
}

signed main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	#if 1
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	#endif
	
	int a, b;
	cin >> a >> b;
	
	vector<int> sz(a + 1);
	
	for(int i = 1; i <= a; ++ i)
		cin >> sz[i];
	
	sort(sz.begin() + 1, sz.end());
	
	int l = 1, r = a, ans = 1;
	
	while(l <= r){
		const int mid = l + r >> 1;
		
		if(check(sz, a, mid) <= b)
			ans = mid,
			l = mid + 1;
		else
			r = mid - 1;
	}
	
	cout << ans;
		
	return 0;
}
