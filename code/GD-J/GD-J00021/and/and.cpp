#include <bits/stdc++.h>
using namespace std;

int n, m, x, ma = INT_MIN;
vector<int> a;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	a.resize(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(m == 1){
		cout << *max_element(a.begin(), a.end()) << '\n';
	}
	else if(m == 2){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j < i; j++){
				ma = max(ma, a[i] & a[j]);
			}
		}
		cout << ma << '\n';
	}
	else if(m == n - 1){
		for(int i = 1; i <= n; i++){
			if(i != 1){
				x = a[1];
			}
			else{
				x = a[2];
			}
			for(int j = 1; j <= n; j++){
				if(j != i){
					x = x & a[j];
				}
			}
			ma = max(ma, x);
		}
		cout << ma << '\n';
	}
	else if(m == n){
		x = a[1];
		for(int j = 1; j <= n; j++){
			x = x & a[j];
		}
		cout << x << '\n';
	}
	else{
		sort(a.begin() + 1, a.end() + 1, greater<int>());
		cout << a[m] << '\n';
	}
	return 0;
}
