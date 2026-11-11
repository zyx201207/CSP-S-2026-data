#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, ans = 0;
vector<int> a, tmp;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	for(int i = 30; i >= 0; i--) {
		int cnt = 0;
		for(auto it : a)
			cnt += (it >> i & 1);
		if(cnt >= m) {
			tmp.clear();
			for(auto it : a)
				if((it >> i & 1) == 1) {
					tmp.push_back(it);
				}
			a.swap(tmp);
			ans += (1 << i);
		}
	}
	cout << ans;
	return 0;
}