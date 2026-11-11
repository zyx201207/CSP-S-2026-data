#include <bits/stdc++.h>
using namespace std;
///
long long n, m, cnt=1, maxis;
vector<int> a;

void dfs(int num, int result, vector<int> used) {
	if (num >= m) {
		maxis = max(maxis, (long long)result);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (find(used.begin(), used.end(), i) == used.end()){//Ã»ÕÒµ½ 
			used.push_back(i);
			if (result == -1) {
				dfs(num+1, a[i], used); 
			}
			else {
				dfs(num+1, (result&a[i]), used); 
			}
			used.pop_back();
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	a.resize(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> oiwiki;
	dfs(0, -1, oiwiki);
	cout << maxis;
	return 0;
}
