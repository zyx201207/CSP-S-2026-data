#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
bool fab;
vector<int> a; 
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	for (int i = 1; i < n; `i++){
		if(a[i] - a[i - 1] != a[1] - a[0]) fab = 0;
	}
	if(fab){
		int d = a[1] - a[0];
		int ans = 1, le = m;
		for (int j = n - 1; j >= 0; j--){
			if((a[n - 1] - a[j]) <= le){
				ans++;
				le -= (a[n - 1] - a[j]);
			}else break;
		}
		cout << ans << '\n';
	}else{
		int tot = -1;
		for (int i = 1; i < n; i++){
			int ans = 1, le = m;
			for (int j = i - 1; j >= 0; j--){
				if((a[i] - a[j]) <= le){
					ans++;
					le -= (a[i] - a[j]);
				}else break;
			}
			tot = max(tot, ans);
		}
		cout << tot << '\n';
	}
	return 0;
}

// 75pts?
// higher than CSP-S 2025
