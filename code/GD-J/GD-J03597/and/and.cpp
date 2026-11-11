#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;
	cin >> n >> m;
	
	vector<int>s(n + 1);
	for(int i = 1;i <= n;i++){
		cin >> s[i];
	}
	sort(s.begin() + 1,s.end());
	
	int ans = -1e18;
	for(int l = 1;(l + m - 1) <= n;l++){
		int r = (l + m - 1);
		
		int ans_ = s[l];
		for(int k = l;k <= r;k++){
			ans_ &= s[k];
		}
		
		ans = max(ans,ans_);
	} 
	cout << ans << "\n";
	
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T = 1;
	while(T--){
		solve();
	}
	return 0;
}
