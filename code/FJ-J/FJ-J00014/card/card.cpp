#include <bits/stdc++.h>
using namespace std;

int const N = 1e5 + 10;

int a[N], k[N], ans[N];

bool flag1 = true, flag2 = true;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		if(a[i] < a[i - 1]) flag1 = false;
		if(k[a[i]] >= 1) flag2 = false;
		k[a[i]]++;
	}
	if(flag1 == true) {
		for(int i = 1; i <= n; i++) {
			ans[a[i]] = max(ans[a[i]], i);
		}
		for(int i = 1; i <= m; i++) cout << ans[i] << " ";
		cout << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		vector<int> vt;
		for(int j = 0; j <= n - i; j++) {
			for(int k = 0; k < vt.size(); k++) {
				if(vt[k] == a[i + j]) vt.erase(vt.begin() + k, vt.end());
			}
			vt.push_back(a[i + j]);
		}
		for(int i = 0; i < vt.size(); i++) ans[vt[i]]++;
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
