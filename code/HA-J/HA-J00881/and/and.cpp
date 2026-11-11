#include <bits/stdc++.h>
using namespace std;
int a[200010];
vector<int> vec;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,res = INT_MAX;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	while (m--) {
		int mx = -1;
		int t = 0;
		bool flag = false;
		for (int i = 1;i <= n;i++) {
			if (res & a[i] > mx && find(vec.begin(),vec.end(),i) == vec.end()) {
				mx = res & a[i];
				t = i;
				flag = true;
			}
		}
		if (flag) {
			res = mx;
			vec.push_back(t);
		}
	}
	cout << res;
	return 0;
}
