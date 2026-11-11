#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	vector<int> a;
	int n, m, x, ans;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> x;
		a.push_back(x);
	}
	for(int i = 0;i < n;i++){
		for(int j = i;j > 0;j--){
			if(a[j] > a[j - 1]){
				x = a[j];
				a[j] = a[j - 1];
				a[j - 1] = x;
			}
		}
	}
	ans = a[0];
	for(int i = 1;i < m;i++){
		ans = ans & a[i];
	}
	cout << ans;
	return 0;
}
