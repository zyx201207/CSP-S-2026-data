#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(){
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin.tie (nullptr) -> sync_with_stdio (false);
	cin >> n >> m;
	vector <int> a (n + 1); 
	for (int i = 1; i <= n; i++){
		cin >> a [i];
	}
	vector <int> v (n + 1);
	for (int i = 1; i <= n; i++){
		v [i] = a [i];
	}
	int ans = 0;
	for (int i = 31; i >= 1; i--){
		int cnt = 0;
		for (auto j : v){
			if ((j >> (i - 1)) & 1){
				cnt++;
			}
		}
		if (cnt >= m){
			vector <int> v2;
			for (auto j : v){
				if ((j >> (i - 1)) & 1){
					v2.push_back (j);
				}
			}
			v.clear ();
			for (auto j : v2){
				v.push_back (j);
			}
			ans += (1 << (i - 1));
		}
	}
	cout << ans;
	return 0;
}
