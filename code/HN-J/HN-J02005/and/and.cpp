#include <bits/stdc++.h>
#define ll long long
//#define debug(x) cout << #x << ' ' << x << endl;
int n, m;
using namespace std;
int main() {
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0); 
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	vector<int>ve(n + 1);
	vector<int>vq{};
	for (int i = 1;i <= n;i++) {
		cin >> ve[i];
		vq.push_back(i);
	}
	ll ans{}; 
	for (int i = 31;i >= 0;i--) {
		int cnt{};
		vector<int>tmpq{};
		for (auto j : vq) {
			if((ve[j] >> i) & 1 == 1) {
				cnt++;
				tmpq.push_back(j);
			}
		}
		if(cnt >= m) {
//			debug(i);
			ans += (1 << i);
			vq = tmpq;
		}
	}
	cout << ans << '\n';
	return 0;
} 
