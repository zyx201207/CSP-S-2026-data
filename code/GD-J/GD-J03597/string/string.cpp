#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	
	string s;
	vector<int>c(n + 1);
	vector<char>a(n + 1);
	for(int i = 1;i <= n;i++){
		cin >> c[i] >> a[i];
		for(int j = 1;j <= c[i];j++){
			s += a[i];
		}
	}
	
	int ans = 0;
	int len = (s.size() - 1) / 2;
	for(int i = 0;i <= len;i++){
		if(s[i] != s[(s.size() - 1) - i]){
			ans++;
		}
	}
	cout << ans << "\n";
	
	return;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T = 1;
	while(T--){
		solve();
	}
	return 0;
}
