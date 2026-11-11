#include <bits/stdc++.h>
using namespace std;
int n, m, ans[300005];
vector<int> c;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i){
		int x;
		cin >> x;
		c.push_back(x);
	}
	for (int t = 0; t < n; ++t){
		vector<int> l(300005);
		bool have[500005] = {false};
		for (int i = t; i < n; ++i){
			if (have[c[i]]) for (int j = l[c[i]]; j < i; ++j) have[c[j]] = false;
			have[c[i]] = true;
			l[c[i]] = i;
		}
		for (int i = 1; i <= m; ++i) ans[i] += ((have[i]) ? 1 : 0);
	}
	for (int i = 1; i <= m; ++i) cout << ans[i] << " ";
	return 0;
}
