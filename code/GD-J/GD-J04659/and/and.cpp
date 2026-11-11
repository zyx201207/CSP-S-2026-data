#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> a[2];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m, ans = 0;
	bool t = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		a[t].push_back(k);
	}
	for(int k = 1 << 30; k >= 1; k >>= 1){
		int cnt = 0;
		for(int val : a[t]){
			if(val & k) cnt++;
			if(cnt == m){
				for(int val : a[t]){
					if(val & k){
						a[!t].push_back(val);
					}
				}
				t = !t;
				ans += k;
				break;
			}
		}
		a[!t].clear();
		if(a[t].size() < m) break;
	}
	
	cout << ans;
}
/*
5 3
31 3 1 15 7
*/
