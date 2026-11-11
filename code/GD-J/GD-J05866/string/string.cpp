#include<bits/stdc++.h>
using namespace std;

int n;
vector<long long> as;
vector<char> cs;
long long ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;

	as.reserve(n);
	cs.reserve(n);

	for (int i = 0; i < n; i++) {
		int a; char c;
		cin >> a >> c;
		// ac.push_back({a, c});
		// ac.emplace_back(a, c);
		as.push_back(a);
		cs.push_back(c);
	}

	int l = 0, r = n - 1;
	long long l_idx = as[l], r_idx = as[r];
	while (l < r) {
		// cout << l << ":" << l_idx << " " << r << ":" << r_idx << endl;
		if (l_idx == r_idx) {
			if (cs[l] != cs[r]) {
				ans+=as[l];
			}
			l++; r--;
			l_idx=as[l];
			r_idx=as[r];
			continue;
		}

		if (l_idx < r_idx) {
			if (cs[l] != cs[r]) {
				ans+=l_idx;
			}
			l++;
			r_idx-=l_idx;
			l_idx=as[l];
			continue;
		}

		if (l_idx > r_idx) {
			if (cs[l] != cs[r]) {
				ans+=r_idx;
			}
			r--;
			l_idx-=r_idx;
			r_idx=as[r];
			continue;
		}
	}

	cout << ans;
	
	return 0;
} 
