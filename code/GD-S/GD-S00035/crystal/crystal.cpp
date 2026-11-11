#include <bits/stdc++.h>
using namespace std;

int n, m, mi = INT_MAX, ma = INT_MIN, l, r, mid, x;
vector<int> a, d;

bool check(int x){
	int sum = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] > x){
			if(sum <= m){
				return true; 
			}
			else{
				return false;
			}
		}
		sum += x - a[i];
	}
	if(sum <= m){
		return true; 
	}
	else{
		return false;
	}
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	a.resize(n + 1), d.resize(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mi = min(mi, a[i]), ma = max(ma, a[i]);
	}
	sort(a.begin(), a.end());
	l = mi, r = ma;
	while(l <= r){
		mid = l + (r - l >> 1);
		if(check(mid)){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	x = upper_bound(a.begin() + 1, a.end() + 1, l) - (a.begin() + 1);
	cout << x << '\n';
	return 0;
} 
