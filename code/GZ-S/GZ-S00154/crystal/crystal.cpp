#include<bits/stdc++.h>
using namespace std;

int maxium(int a, int b) {
	return a >= b ? a : b;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, min;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> d(n);

	for(int i=0; i<n; i++) {
        int indata;
        cin >> indata;
        a[i] = indata;
        d[i] = indata;
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for(int i=0; i<n; i++) {
		int tot=m, ansc=0;
		for(int j=i; j>=0;--j) {
			if (a[i]-a[j] <= tot) {
				tot -= a[i]-a[j];
				ansc++;
			}
		ans = maxium(ans, ansc);
		}
	}
	cout << ans <<"\n";
    return 0;
}
