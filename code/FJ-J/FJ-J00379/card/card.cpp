#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, k;
ll a[500010], ans[500010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int m = 1; m <= n; m++) {
		vector<ll> v;
		for (int i = m; i <= n; i++) {
			for (int j = 0; j < v.size(); j++) {
				if (v[j] == a[i]) {
					v.erase(v.begin() + j, v.end());
					break;
				}
			}
			v.push_back(a[i]);
		}
		for (auto it : v) {
			ans[it]++;
		}
	}
	for (int i = 1; i <= k; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}

/*
4 3
1 2 1 3
3 1 4

10 3
3 1 2 1 3 2 3 1 2 1
10 3 3
*/ 
