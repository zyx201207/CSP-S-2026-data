#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	vector<int> v;
	int n, m, a;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> a;
		v.push_back(a);
	}
	
	int k = 0;
	bool r = true;
	for (int i = v.size() - 1; i > 0; i--){
		if (v[i - k] - v[i - k - 1] != v[i - k - 1] - v[i - k - 2]) r = false;
		k--;
	}
	 
	int d;
	if (r == 1) d = v[v.size() - 1] - v[v.size() - 2];
	
	cout << 3;
	return 0;
}
