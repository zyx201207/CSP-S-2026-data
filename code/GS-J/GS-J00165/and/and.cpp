#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m, a;
	cin >> n >> m;
	vector<int> q;
	for (int i = 0; i < n; i++){
		cin >> a;
		v.push_back(a);
	}
	
	for (int i = 0; i < v.size() - 1; i++){
		for (int j = i; j < v.size() - 1; j++){
			if (v[j] < v[j + 1]) swap(v[j], v[j + 1]);
		}
	}
	
	int ans;
	for (int i = 0; i < m; i++){
		if (i == 0) ans = v[0];
		else ans &= v[i];
	}
	cout << ans;
	
	return 0;
}
