#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	auto isa = [&](vector<int> &a, int n){
		bool rt = 1;
		for(int i = 0; i < n; i ++){
			if(a[i] + 1 & a[i]) rt = 0;
		}
		return rt;
	};
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(auto &v : a) cin >> v;
	int maxn = *max_element(a.begin(), a.end());
//	if(n <= 20){
//		int ans = 0;
//		auto dfs = [&](auto &dfs, int x, int an, int num) -> void{
//			if(x == n && num < m){
//				return; 
//			}
//			if(num == m){
//				ans = max(ans, an);
//				return;
//			}
//			if(an <= ans){
//				return;
//			}
//			dfs(dfs, x + 1, an & a[x], num + 1);
//			if(n - x > m - num){
//				dfs(dfs, x + 1, an, num);
//			}
//		};
//		dfs(dfs, 0, (1 << 21) - 1, 0);
//		cout << ans << '\n';
//	}
	if(m == 1){
		// debug
		cout << 1 << endl;
		
		cout << maxn << '\n';
	}
	else if(m == n){
		// debug
		cout << 2 << endl;
		int ans = (1 << 31) - 1;
		for(auto &v : a) ans &= v;
		cout << ans << '\n'; 
	}
	else if(n <= 3000 && m == 2){
		// debug
		cout << 3 << endl;
		
		int ans = 0;
		for(int i = 0; i < n; i ++) for(int j = 0; j < n; j ++) if(i != j){
			ans = max(a[i] & a[j], ans);
		}
		cout << ans << '\n';
	}
	else if(m == n - 1){
		// debug
		cout << 4 << endl;
		
		vector<int> s1(n), s2(n);
		s1[0] = a[0];
		for(int i = 1; i < n; i ++) s1[i] = s1[i - 1] & a[i];
		s2[n - 1] = a[n - 1];
		for(int i = n - 2; i >= 0; i --) s2[i] = s2[i + 1] & a[i];
		
		int ans = max(s2[1], s2[n - 2]);
		for(int i = 1; i < n - 1; i ++){
			ans = max(s1[i - 1] & s2[i + 1], ans);
		}
		cout << ans << '\n';
	}
	else if(isa(a, n)){
		// debug
		cout << 5 << endl;
		
		sort(a.begin(), a.end(), greater<int>());
		int ans = a[m - 1];
		cout << ans << '\n';
	}
	else{
		// debug
		cout << 6 << endl;
		sort(a.begin(), a.end(), greater<int>());
		// debug
		cout << 6 << endl;
		
		int ans = 0;
		for(int mask = 1; mask <= maxn; mask ++){
			int num = 0, cur = (1 << 11) - 1;
			for(int i = 0; i < n && num < m; i ++) if(a[i] & mask >= mask){
				num ++;
				cur &= a[i];
			}
//			// debug
//			cout << mask << ' ' << num << ' ' << cur << cur & 512 << endl;
			if(num == m){
				ans = cur;
				mask = cur;
			}
		}
		cout << ans << '\n';
	}
}
