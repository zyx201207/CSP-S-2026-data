#include <bits/stdc++.h>
using namespace std;

int c, t, n, d;
vector<int> x, dp;

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> t;
	for(int i = 1; i <= t; i++){
		cin >> n >> d;
		x.resize(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
	}
	return 0;
} 
