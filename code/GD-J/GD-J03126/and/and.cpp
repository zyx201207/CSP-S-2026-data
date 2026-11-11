#include <bits/stdc++.h>
using namespace std;
int n;
int m;
vector<int> a;
int maxans;
int lf(int y, int k, int now){
	if(y == 0){
		maxans = max(maxans, now);
		return 0;
	}
	if(k == n){
		return 0;
	}
	for(int i = k; i < n; i++){
		lf(y - 1, i + 1, now & a[i]);
	}
	return 0;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int use = 2147483647;
	int maix = 0;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		a.push_back(x);
		use |= x;
		maix = max(maix, x);
	}
	int ans = 0;
	if(m == n){
		cout << use;
		return 0;
	}
	if(m == 1){
		cout << maix;
		return 0;
	}
	if(m == 2){
		for(int i = 0; i < n - 1; i++){
			for(int l = i + 1; l < n; l++){
				ans = max(a[i] & a[l], ans);
			}
		}
		cout << ans;
		return 0;
	}
	if(m == n - 1){
		int mmmm = 0;
		for(int i = 0; i < n; i++){
			int nowans = 2147483647;;
			for(int l = 0; l < n; l++){
				if(l != i){
					nowans &= a[l];
				}
			}
			mmmm = max(mmmm, nowans);
		}
		cout << mmmm;
		return 0;
	}
	lf(m, 0, 2147483647);
	cout << maxans;
	return 0;
}
