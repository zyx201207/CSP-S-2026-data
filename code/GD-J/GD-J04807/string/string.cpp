#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	
	vector<int> a(n + 1);
	vector<char> c(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	
	long long ans = 0;
	
	for(int l = 1, r = n; l < r; l++){
		while(a[l] && l < r){
			int mn = min(a[l], a[r]);
			if(c[l] != c[r]) ans += mn;
			a[l] -= mn;
			a[r] -= mn;
			if(a[r] == 0) r--;
		}
	}
	
	cout << ans << '\n';
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T = 1;
	while(T--) solve();
	return 0;
}//pls±ð¿¨ÎÒ 
