#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	for(auto &x : p) cin >> x;
	int ans = 0;
	for(int i = 30; i >= 0; i--){
		vector<int> np;
		for(int x : p)
			if((x >> i) & 1) np.push_back(x);
		if((int)np.size() >= m){
			p.swap(np);
			ans += (1 << i);
		}
	}
	cout << ans;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T = 1;
	while(T--) solve();
	return 0;
}//pls±ð¿¨ÎÒ 
