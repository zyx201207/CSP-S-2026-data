#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define N 200010

int n, m, a[N];
int num[N][35];
int ans[35];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++) {
		int t = a[i], cur = 0;
		while(t != 0) {
			num[i][33 - cur] = t % 2;
			cur++;
			t /= 2;
		}
	}
	
	vector<int> s;
	for(int i = 1;i <= n;i++) {
		s.push_back(i);
	}
	
	for(int i = 1;i <= 33;i++) {
		int sum = 0;
		for(auto j:s) {
			sum += num[j][i];
		}
		if(sum >= m) { 
			ans[i] = 1;
			vector<int> ns;
			for(auto j:s) {
				if(num[j][i] == 1)
					ns.push_back(j);
			}
			s = ns;
		} else {
			ans[i] = 0;
		}
	}
	
	int sum = 0;
	for(int i = 1;i <= 33;i++) {
		sum = sum * 2 + ans[i];
	}
	cout << sum << "\n";
	return 0;
}
